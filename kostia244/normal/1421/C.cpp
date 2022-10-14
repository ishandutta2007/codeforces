#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 330, mod = 1000000007;
char mat[maxn][maxn];
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	cout << "3\n";
	cout << "L 2\n";n++;
	cout << "R " << 2 << "\n"; n = 2*n-2;
	cout << "R " << n-1 << "\n";
}