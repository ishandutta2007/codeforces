#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int l[5], p[5], r[5], s[5];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i <= 4; i++) cin >> l[i] >> s[i] >> r[i] >> p[i];
	if(p[1]&&(s[1]||r[1]||l[1]||s[3]||r[4]||l[2])) return cout << "YES", 0;
	if(p[3]&&(s[3]||r[3]||l[3]||s[1]||r[2]||l[4])) return cout << "YES", 0;
	if(p[2]&&(s[2]||r[2]||l[2]||s[4]||r[1]||l[3])) return cout << "YES", 0;
	if(p[4]&&(s[4]||r[4]||l[4]||s[2]||r[3]||l[1])) return cout << "YES", 0;
	cout << "NO";
	return 0;
}