#include <bits/stdc++.h>
#define maxn 505

using namespace std;

const int p = 998244353;

int n;
int a[maxn];
char s[maxn];
int f[maxn][maxn];
vector<pair<int, int> > v;
bool tag[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%s", s);
		if(s[0] == '+') scanf("%d", &a[i]), v.push_back({a[i], i});
		else a[i] = 0;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0;i < v.size();i++){
		f[0][0] = 1;
		for(int j = 1;j <= n;j++){
			for(int k = 0;k <= n;k++){
				if(j == v[i].second){
					f[j][k] = f[j - 1][k];
					continue;
				}
				if(!a[j]){
					f[j][k] = (f[j - 1][k] + f[j - 1][k + 1]) % p;
					if(k == 0 && j < v[i].second) f[j][k] = (f[j][k] + f[j - 1][k]) % p;
					continue;
				}
				if(!tag[j]){
					f[j][k] = (f[j - 1][k] + f[j - 1][k]) % p;
					continue;
				}
				f[j][k] = f[j - 1][k];
				if(k) f[j][k] = (f[j][k] + f[j - 1][k - 1]) % p;
			}
		}
		int sum = 0;
		for(int j = 0;j <= n;j++) sum = (sum + f[n][j]) % p;
		ans = (ans + 1ll * sum * v[i].first) % p;
		tag[v[i].second] = true;
	}
	printf("%d", ans);
}