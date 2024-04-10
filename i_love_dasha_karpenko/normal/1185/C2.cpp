#include <bits/stdc++.h>

using namespace std;
#define DIM  200007
#define DIM2 107
#define INF 10E16
#define MAXN 2750137
#define LG 18
#define MODULO 1000000007
#define MODULO2 MODULO*2
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef ll arr[DIM];
typedef vector<ll> vec;
typedef vector<ll> graph[DIM];
typedef pll parr[DIM];
typedef ll table[DIM][DIM2];
typedef ll arr2[DIM2];
typedef pair<string, string> ps;
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

ll n, m;
arr A;
map<ll, ll> M;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	ll sum = 0;
	M[-1] = 1;
	auto et = M.begin();
	for (int i = 1; i <= n; i++) {

		ll t = m - A[i];
		ll r = sum - t;
		if (r <= 0) {
			cout << 0 << ' ';
			sum += A[i];
			ll olds = M.count(A[i]);
			if (A[i] < (*et).first)olds = 1;
			M[A[i]]++;
			if (olds == 0)
				et++;
			continue;
		}
		ll s = 0;
		ll e = 0;
		auto it = et;
		ll tt = M.size();
		while (s < r) {
			
			ll cof = (r - s) / (*it).first;
			if ((r - s) % (*it).first != 0)cof++;
			cof = min(cof, (*it).second);
			s += cof * (*it).first;
			e+=cof;
			if (tt > 0)
				it--;
			tt--;
		}
		cout << e << ' ';
		sum += A[i];
		ll olds = M.count(A[i]);
		if (A[i] < (*et).first)olds = 1;
		M[A[i]]++;
		if (olds==0)
			et++;
	}
}