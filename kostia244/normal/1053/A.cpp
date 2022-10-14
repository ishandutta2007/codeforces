//#pragma GCC optimize("trapv")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 3e5 + 55;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, g = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	ll on = n;
	ll om = m;
	g = __gcd(n, k);
	n/=g, k/=g;
	g = __gcd(m, k);
	m/=g, k/=g;
	if(k>2) return cout << "NO", 0;
	if(k==1) {
		if(2*n<=on) n*=2;
		else m*=2;
	}
	cout << "YES\n";
	cout << "0 0\n";
	cout << "0 " << m << "\n";
	cout << n << " 0\n";
}