#include <bits/stdc++.h>

using namespace std;
#define DIM  1007
#define DIM2 507
#define INF 4294967296
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
ll l;
stack<ll> S;
int main()
{
	cin >> l;
	ll flag = 0;
	ll cof = 1, res = 0;
	for (int h = 1; h <= l; h++) {
		string x; cin >> x; ll num;
		if (x == "for") {
			cin >> num;
			S.push(num);
			ll dcof = cof;
			dcof *= num;
			if (dcof >= INF || flag != 0) {
				flag++;
			}
			else {
				cof *= num;
			}
		}
		if (x == "add") {
			if (cof >= INF || cof < 0 || flag != 0) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
			res += cof;
			if (res >= INF || res < 0) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
		}
		if (x == "end") {
			if (flag > 0)flag--;
			else cof /= S.top();
			S.pop();
		}
	}
	cout << res << endl;
}
// 011 1