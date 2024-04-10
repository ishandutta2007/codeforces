#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

typedef long long ll;

#define MOD 1000000007LL

void mul(ll *a, ll *b) {
	ll t[4];
	REP(i,2) REP(j,2) {
		t[i*2+j] = 0;
		REP(k,2) t[i*2+j] += a[i*2+k]*b[k*2+j];
		t[i*2+j] %= MOD;
	}
	REP(i,2) REP(j,2) a[i*2+j] = t[i*2+j];
}

int main() {
	ll r[4] = {1,0,0,1};
	ll m[4] = {3,1,1,3};
	ll N;
	cin >> N;
	while (N) {
		if (N&1) {
			mul(r, m);
		}
		mul(m, m);
		N >>= 1;
	}
	ll res = r[0];
	cout << res << endl;
	return 0;
}