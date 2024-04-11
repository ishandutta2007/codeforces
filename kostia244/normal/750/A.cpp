#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define pow loli
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 3030;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int x = 4*60, k, n;
	cin >> n >> k;
	x -= k;
	int ans = 0;
	while(ans < n && (ans+1)*5 <= x) x -= ++ans*5;
	cout << ans << '\n';
	return 0;
}