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
typedef unsigned long  ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 998244353 
#define MAXN 1000000
const long long INF = 10E16;
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
	ll l, r, end, val;
	bool operator < (const node& b)const {
		return val < b.val;
	}
	bool operator > (const node& b)const {
		return val > b.val;
	}
};
bool mc(node a, node b) {
	return a.l < b.l;
}
ll n,x,y,A[DIM];
int main() {
	schnell;
	cin >> n>>x>>y;
	forn(i, n) {
		cin >> A[i];
	}
	forn(i, n) {
		ll flag = 0;
		for (ll j = i - 1; j >= max(ll(1), i - x); j--) {
			if (A[j] <= A[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)continue;
		for (ll j = i + 1; j <=min(n, i + y); j++) {
			if (A[j] <= A[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}