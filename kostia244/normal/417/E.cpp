//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
ll a[110], b[110], n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n==1) {
		a[1] = 1;
	} else if(n==2) {
		a[1] = 3;
		a[2] = 4;
	} else {
		for(int i = 1; i < n; i++) a[i] = 2;
		a[n] = n-2;
	}
	if(m==1) {
		b[1] = 1;
	} else if(m==2) {
		b[1] = 3;
		b[2] = 4;
	} else {
		for(int i = 1; i < m; i++) b[i] = 2;
		b[m] = m-2;
	}
	for(int i = 1; i <= n; i++, cout << "\n")
		for(int j = 1; j <= m; j++)
			cout << a[i]*b[j] << " ";
}