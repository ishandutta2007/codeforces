#include <bits/stdc++.h>

using namespace std;
#define DIM  1007
#define DIM2 507
#define INF 10E16
#define MAXN 107
#define LG 18
#define MODULO 1000000007
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
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
ll t,n,k;
int main()
{
	cin >> t;
	for (int h = 1; h <= t; h++) {
		cin >> n >> k;
		ll res = 0;
		while (n > 0) {
			if (n == 1) {
				res++;
				break;
			}
			while(n % k == 0) {
				if (n == 1) {
					res++;
					break;
				}
				n /= k;
				res++;

			}
			if (n%k!=0){
				ll num = n / k * k;
				res += n - num;
				n = num;
			}
		}
		cout << res << endl;
	}
}
// 011 1