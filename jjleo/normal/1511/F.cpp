#include <bits/stdc++.h>
#define maxn 305

using namespace std;

const int p = 998244353;

int edge[maxn][26];
bool tag[maxn];
int cnt;
char s[maxn];

int n, m;
vector<pair<int, string> > v;
vector<pair<int, int> > w;
map<pair<int, int>, int> mp;

inline bool check(string a, string b){
	if(a.length() > b.length()) swap(a, b);
	for(int i = 1;i <= a.length();i++) if(a[a.length() - i] ^ b[b.length() - i]) return false;
	return true;
}

struct Matrix{
	int a[maxn][maxn];
	
	inline Matrix operator * (const Matrix &A) const {
		Matrix B;
		for(int i = 0;i < w.size();i++) for(int j = 0;j < w.size();j++) B.a[i][j] = 0;
		for(int i = 0;i < w.size();i++){
			for(int j = 0;j < w.size();j++){
				for(int k = 0;k < w.size();k++){
					B.a[i][j] = (B.a[i][j] + 1ll * a[i][k] * A.a[k][j]) % p;
				}
			}
		}
		return B;
	}
};

int main(){
	scanf("%d%d", &n, &m);
	v.push_back({0, ""});
	for(int i = 1;i <= n;i++){
		scanf("%s", s + 1);
		int len = strlen(s + 1), now = 0;
		string S;
		for(int j = 1;j <= len;j++){
			S += s[j];
			if(!edge[now][s[j] - 'a']) v.push_back({edge[now][s[j] - 'a'] = ++cnt, S});
			now = edge[now][s[j] - 'a'];
		}
		tag[now] = true;
	}
	for(int i = 0;i < v.size();i++){
		for(int j = i;j < v.size();j++){
			if(check(v[i].second, v[j].second)){
				w.push_back({v[i].first, v[j].first});
				mp[{v[i].first, v[j].first}] = mp[{v[j].first, v[i].first}] = w.size() - 1;
			}
		}
	}
	Matrix X;
	for(int i = 0;i < w.size();i++) for(int j = 0;j < w.size();j++) X.a[i][j] = 0;
	for(int i = 0;i < w.size();i++){
		int x = w[i].first, y = w[i].second;
		for(int j = 0;j < 26;j++){
			if(edge[x][j] && edge[y][j]) X.a[i][mp[{edge[x][j], edge[y][j]}]]++;
			if(tag[x] && edge[0][j] && edge[y][j]) X.a[i][mp[{edge[0][j], edge[y][j]}]]++;
			if(tag[y] && edge[x][j] && edge[0][j]) X.a[i][mp[{edge[x][j], edge[0][j]}]]++;
			if(tag[x] && tag[y] && edge[0][j]) X.a[i][mp[{edge[0][j], edge[0][j]}]]++;
		}
	}
	Matrix A;
	for(int i = 0;i < w.size();i++) for(int j = 0;j < w.size();j++) A.a[i][j] = i == j;
	while(m){
		if(m & 1) A = A * X;
		X = X * X, m >>= 1;
	}
	Matrix B;
	for(int i = 0;i < w.size();i++) for(int j = 0;j < w.size();j++) B.a[i][j] = (i + j == 0);
	B = B * A;
	int ans = 0;
	for(int i = 0;i < w.size();i++){
		int x = w[i].first, y = w[i].second;
		if(tag[x] && tag[y]) ans = (ans + B.a[0][i]) % p;
	}
	printf("%d", ans);
}