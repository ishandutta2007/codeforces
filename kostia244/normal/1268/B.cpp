#pragma GCC optimize("trapv")
//#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 2e5 + 55;
const int mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, t, a = 0, b = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a += t/2;
		b += t - (t/2);
		swap(a, b);
	}
	cout << min(a, b);
}