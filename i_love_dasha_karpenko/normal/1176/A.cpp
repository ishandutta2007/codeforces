#include <bits/stdc++.h>

using namespace std;
#define DIM  3007
#define DIM2 100007
#define INF 10E16
#define MAXN 107
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;

struct pp {
	ll a, b;
	bool operator <(const pp& V)const {
		if (a == V.a)return b < V.b;
		return a < V.a;
	}
	bool operator ==(const pp& V)const {
		if (a == V.a && b == V.b)return 1;
		return 0;
	}
};
ll n,q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >>q;
	for (int h = 1; h <= q; h++) {
		cin >> n;
		ll res = 0;
		while (n % 5 == 0) {
			n = (n * 4) / 5;
			res++;
		}
		while (n % 3 == 0) {
			n = (n * 2) / 3;
			res++;
		}
		while (n % 2 == 0) { n /= 2; res++; }
		if (n != 1) {
			cout << -1 << endl;
		}
		else {
			cout << res << endl;
		}
	}
	
}