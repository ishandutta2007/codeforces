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
int ms[1 << maxn];
int ma[maxm];
int fk[maxm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int t;
	for(cin >> t; t; t -= 1){
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= m; i += 1) ma[i] = 0;
		for(int i = 0; i < n; i += 1)
			for(int j = 1; j <= m; j += 1){
				 cin >> a[i][j];
				 ma[j] = max(ma[j], a[i][j]);
			}
		for(int i = 1; i <= m; i += 1) fk[i] = i;
		sort(fk + 1, fk + m + 1, [&](const int &x, const int &y){
			return ma[x] > ma[y];
		});
		for(int i = 1; i <= min(n, m); i += 1){
			for(int j = 0; j < (1 << n); j += 1){
				 f[i][j] = f[i - 1][j];
				 ms[j] = 0;
			}
			for(int k = 0; k < n; k += 1){
				for(int x = 0; x < n; x += 1) pa[x] = a[(x + k) % n][fk[i]];
				for(int j = 0; j < (1 << n); j += 1){
					s[j] = 0;
					for(int x = 0; x < n; x += 1) if((j >> x) & 1) s[j] += pa[x];
					ms[j] = max(s[j], ms[j]);
				}
			}
			for(int j = 0; j < (1 << n); j += 1)
				for(int x = j; x; x = (x - 1) & j){
					f[i][j] = max(f[i - 1][j ^ x] + ms[x], f[i][j]);
				}
		}
		cout << f[min(n, m)][(1 << n) - 1] << "\n";
	}
	return 0;
}