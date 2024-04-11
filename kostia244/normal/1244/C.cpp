#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vvi g;
vi a;
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n, p, d, w;
	cin >> n >> p >> w >> d;
	for(ll dc = 0; dc*d <= p && dc < w; dc++) {
		if((p - dc*d)%w == 0 && (p - dc*d)/w + dc <= n) {
			cout << (p - dc*d)/w << " " << dc << " " << n-(p - dc*d)/w-dc;
			return 0;
		}
	}
	cout << -1;
}