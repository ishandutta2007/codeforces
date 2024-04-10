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
#define po(x) 1<<x
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
#define DIM 100007
#define DIM2 10007
#define MODULO 1000000007
#define MAXN 10E9
const ll INF = 10E16;
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

ll x, y, z, a, b, c;
int main() {
	schnell;
	cin >> x >> y >> z >> a >> b >> c;
	ll flag = 0;
	if (a >= x) {
		a -= x;
		if (a + b >= y) {
			b += a;
			b -= y;
			if (b + c >= z) {
				flag = 1;
			}
		}
	}
	if (flag)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}