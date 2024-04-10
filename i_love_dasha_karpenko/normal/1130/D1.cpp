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
#define DIM 107
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 10E18
const ll INF = 10E18;
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
ll n, m,mod,pos[DIM];
vector<ll> A[DIM];
bool mc(ll x, ll y) {
	return x > y;
}
int main() {
	schnell;
	cin >> n>>m;
	forn(i, m) {
		ll x, y;
		cin >> x >> y;
		ll r = y - x;
		if (r < 0)r += n;
		A[x].pb(r);
	}
	forn(i, n) {
		mod = i;
		//A[i].pb(0);
		sort(A[i].begin(), A[i].end(),mc);
	}
	forn(i, n) {
		ll r = 0,last = i+1,res = 1,ii = i,y = i;
		memset(pos, 0, sizeof(pos));
		while ( r!= m) {
			if (pos[i] < A[i].size()) {
				ll to =y+A[i][pos[i]];
				if (to>last) {
					res += to - last;
					last = to;
				}
				r++;
			}
			pos[i]++;
			
			i++;
			if (i > n) {
				i = 1;
			}
			y++;
			
		}
		cout << res << ' ';
		i = ii;
	}
	cout << endl;
	return 0;
}