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
typedef long ll;
typedef long double ld;
#define DIM 14
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
int main() {
	schnell;
	cin >> n;
	ll res1 = 0, res2 = 0,num1,num2;
	forn(i, n) {
		ll x;
		cin >> x;
		if (x > 0) {
			res1++;
			num1 = x;
		}
		else if (x<0){
			res2++;
			num2 = x;
		}
	}
	ll cof = n / 2;
	if (n % 2 != 0)cof++;
	if (res1 < cof && res2<cof) {
		cout << 0 << endl;
		return 0;
	}
	if (res1 > res2)cout << num1 << endl;
	else cout << num2 << endl;
}