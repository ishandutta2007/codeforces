#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define MS0(I) memset(I, 0, sizeof(I));
#define MS1(I) memset(I, -1, sizeof(I));
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, s, n) for(int i = (s); i < (n); ++i)
#define per1(i, a, b) for(int i = a; i >= b; --i)
#define DRI(A) int A; scanf("%d", &A);
#define DRII(A, B) int A, B; scanf("%d %d", &A, &B);
#define DRIII(A, B, C) int A, B, C; scanf("%d %d %d", &A, &B, &C);
#define SZ(X) ((int)X.size() )
#define MP make_pair 
#define pb push_back
#define F first
#define S second
#define ALL(I) (I).begin(), (I).end()
typedef const void CV;
typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
typedef long double LDB;
typedef pair<int, int> PII; 
const double eps = 1e-9;
const double PI = acos(-1);
const LL INFF = 1e18;
const int INF = 1e9;
const int mod = 1e9+7;
const int MAX = 1e6+7;
vector<LL>stx, sty;
map<pair<LL, LL>, bool>mp;
LL ll, rr;
inline bool jg(LL u, LL v){
	if(u < ll || v > rr) return 0;
	return 1;
}
LL gcd(LL u, LL v){
	while(u){
		LL tmp = v % u;
		v = u;
		u = tmp;
	}
	return v;
}
int main(void){
	scanf("%lld %lld", &ll, &rr);
	DRII(x, y);
	LL val = (LL)x*y;
	int h = sqrt(x+1);
	rep1(i, 1, h+1){
		if(x % i == 0) stx.pb(i);
	}
	h = sqrt(y+1);
	rep1(i, 1, h+1){
		if(y % i == 0) sty.pb(i);
	}
	LL ans = 0;
	for(LL v1 : stx){
		for(LL v2 : sty){
			LL u = v1*v2;
			LL v = val / u;
			if(u > v) swap(u, v);
			if(jg(u, v) && !mp[MP(u, v)] && gcd(u, v) == x){
				mp[MP(u, v)] = 1;
				if(u == v) ans++;
				else ans+=2;
			}
			u = v1*(y/v2);
			v = val / u;
			if(u > v) swap(u, v);
			if(jg(u, v) && !mp[MP(u, v)] && gcd(u, v) == x){
				mp[MP(u, v)] = 1;
				if(u == v) ans++;
				else ans+=2;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}