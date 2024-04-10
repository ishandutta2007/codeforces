#include <bits/stdc++.h>

using namespace std;
#define DIM  307
#define DIM2 107
#define INF 10E16
#define MAXN 107
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long  ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
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
ll t, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	for (int h = 1; h <= t; h++) {
		cin >> n;
		ll res = 0, x,res1 = 0,res2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			if (x % 3 == 0) {
				res++; 
			}
			if (x%3==1) {
				res1++;
			}
			if (x % 3 == 2)res2++;
		}
		
			res += abs(res1 - res2) / 3;
		cout << res+min(res1,res2) << endl;
	}
}