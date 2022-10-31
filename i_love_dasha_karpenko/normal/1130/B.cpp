#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
using namespace std;
#define pb push_back
#define po(x) (1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 10E18
const ll INF = po(30);
const ll mask = po(9) - 1;
struct pp {
	ll fi, sc;
	bool operator < (const pp& b)const {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool operator > (const pp& b)const {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool operator == (const pp& b)const {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
struct node {
	ll x, m, num;
};
ll n;
vector<ll> V[DIM];
ll start(ll pos, ll num) {
	ll res = 0;
	while (num != n) {
		if (abs(pos - V[num + 1][0]) < abs(pos - V[num + 1][1])) {
			res += abs(pos - V[num + 1][0]);
			pos = V[num + 1][0];
		}
		else {
			res += abs(pos - V[num + 1][1]);
			pos = V[num + 1][1];
		}
		num++;
	}
	return res;
}
int main() {
	schnell;
	cin >> n;
	forn(i, n * 2) {
		ll x; cin >> x;
		V[x].pb(i);
	}
	ll num = 1,res = 0,pos = V[1][0];
	res += V[1][0]-1;
	while (num != n) {
		res += abs(V[num + 1][0] - pos);
		pos = V[num + 1][0];
		num++;
	}
	num = 1, pos = V[1][1];
	res += V[1][1]-1;
	while (num != n) {
		res += abs(V[num + 1][1] - pos);
		pos = V[num + 1][1];
		num++;
	}
	cout << res << endl;

}