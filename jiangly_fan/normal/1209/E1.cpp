//Author: HeXun
//Date: 09-14-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 12;
constexpr int maxm = 2400;
int a[maxn][maxm];
int f[maxm][1 << maxn];
int pa[maxn];
int s[1 << maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i += 1)
			for(int j = 1; j <= m; j += 1) cin >> a[i][j];
		for(int i = 1; i <= m; i += 1){
			for(int j = 0; j < (1 << n); j += 1) f[i][j] = 0;
			for(int k = 0; k < n; k += 1){
				for(int x = 0; x < n; x += 1) pa[x] = a[(x + k) % n][i];
				for(int j = 0; j < (1 << n); j += 1){
					s[j] = 0;
					for(int x = 0; x < n; x += 1) if((j >> x) & 1) s[j] += pa[x];
				}
				for(int j = 0; j < (1 << n); j += 1)
					for(int x = 0; x < (1 << n); x += 1) if((x & j) == x){
						f[i][j] = max(f[i - 1][j ^ x] + s[x], f[i][j]);
					}
			}
		}
		cout << f[m][(1 << n) - 1] << "\n";
	}
	return 0;
}