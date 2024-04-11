#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 2020, mod = 1000000007;
int n, m;
int Rs[maxn][maxn], Cs[maxn][maxn], Rdp[maxn][maxn], Cdp[maxn][maxn];
void add(int &a, int b) {
	a = a+b>=mod?a+b-mod:a+b;
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	if(n == 1 && m == 1) return cout << "1\n", 0;
	char c;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> c;
			Rs[i][j] = c == 'R';
			Cs[i][j] = c == 'R';
		}
	for(int i = n; i--;)
		for(int j = m; j--;)
			Rs[i][j] += Rs[i+1][j], Cs[i][j] += Cs[i][j+1];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(i) add(Cdp[i][j], Cdp[i-1][j]);
			if(j) add(Rdp[i][j], Rdp[i][j-1]);
			if(i+j == 0) Rdp[i][j]++, Cdp[i][j]++;
			{//row move
				int can = n-i-1-Rs[i+1][j];
				if(can > 0) {
					add(Cdp[i+1][j], Rdp[i][j]);
					add(Cdp[i+can+1][j], mod-Rdp[i][j]);
				}
			}
			{//column move
				int can = m-j-1-Cs[i][j+1];
				if(can > 0) {
					add(Rdp[i][j+1], Cdp[i][j]);
					add(Rdp[i][j+can+1], mod-Cdp[i][j]);
				}
			}
			if(i+j == 0) Rdp[i][j]--, Cdp[i][j]--;
		}
	add(Rdp[n-1][m-1], Cdp[n-1][m-1]);
	cout << Rdp[n-1][m-1] << '\n';
}