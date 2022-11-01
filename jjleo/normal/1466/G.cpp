#include <bits/stdc++.h>
#define maxn 100086
#define maxS 2000086

using namespace std;

const int p = 1e9 + 7, m = 131;

typedef unsigned long long ull;

int n, q;
char t[maxn];
string s;
pair<pair<int, string>, int> a[maxS];
int ans[maxS];
int f[26][maxn], g[maxn], inv[maxn];
ull h[maxS], pres[maxS], sufs[maxS], preS[maxS], sufS[maxS];

inline bool cmp(pair<pair<int, string>, int> x, pair<pair<int, string>, int> y){
	return x.first.second.length() < y.first.second.length();
}

int main(){
	scanf("%d%d", &n, &q);
	cin >> s;
	scanf("%s", t + 1);
	for(int i = 1;i <= q;i++){
		scanf("%d", &a[i].first.first);
		cin >> a[i].first.second;
		a[i].second = i; 
	}
	sort(a + 1, a + 1 + q, cmp);
	g[0] = 1;for(int i = 1;i < maxn;i++) g[i] = (g[i - 1] + g[i - 1]) % p;
	inv[0] = 1, inv[1] = p + 1 >> 1;
	for(int i = 2;i < maxn;i++) inv[i] = 1ll * inv[i - 1] * inv[1] % p;
	h[0] = 1;for(int i = 1;i < maxS;i++) h[i] = h[i - 1] * m;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++){
			f[j][i] = (f[j][i - 1] + (t[i] == j + 'a' ? inv[i] : 0)) % p;
		}
	}
	int x = 0;
	for(int i = 0;i <= n;i++){
		if(i) s = s + t[i] + s;
		for(int j = 1;j <= s.length();j++){
			pres[j] = pres[j - 1] * m + s[j - 1];
		}
		for(int j = s.length();j;j--){
			sufs[j] = sufs[j + 1] + s[j - 1] * h[s.length() - j];
		}
		while(x < q && a[x + 1].first.second.length() <= s.length()){
			string S = a[++x].first.second;
			int sum = 0, N = a[x].first.first;
			if(N < i) continue;
			for(int j = 1;j <= S.length();j++){
				preS[j] = preS[j - 1] * m + S[j - 1];
			}
			for(int j = S.length();j;j--){
				sufS[j] = sufS[j + 1] + S[j - 1] * h[S.length() - j];
			}
			for(int j = S.length();j <= s.length();j++){
				sum += preS[S.length()] == pres[j] - pres[j - S.length()] * h[S.length()];
			}
			sum = 1ll * sum * g[N - i] % p;
			for(int j = 1;j <= S.length();j++){
				if(sufs[s.length() - j + 2] == preS[j - 1] && pres[S.length() - j] == sufS[j + 1]){
					sum = (sum + 1ll * g[N] * (f[S[j - 1] - 'a'][N] + p - f[S[j - 1] - 'a'][i])) % p;
				}
			}
			//printf("%s %s---\n", s.c_str(), S.c_str());
			ans[a[x].second] = sum;
		}
		if(x == q) break;
	}
	for(int i = 1;i <= q;i++) printf("%d\n", ans[i]);
}