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
#include <bitset>
#include <algorithm>
#include <cmath>
#include <locale>
using namespace std;
#define F first
#define S second
#define pb push_back
#define MP make_pair
#define MS0(I) memset(I, 0, sizeof(I));
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define rep(i, n) for(int i = 0; i < n; i ++)
#define rep1(i, a, b) for(int i = a; i < b; i ++)
#define per1(i, a, b) for(int i = a; i >= b; i --)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long LL;
typedef long double LDB;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
//////////////////////
const long double eps = 1e-13;
const long double PI = acos(-1);
const int INF = (int)1e9;
const LL  INFF = (LL)1e18;
const int mod = (int)1e9 + 7;
const int MXN = (int)3e5 + 7;
pair<PII, int>a[MXN];
LL ans[MXN];
bool cmp(const pair<PII, int> &u, const pair<PII, int> &v){
	return u.F.S - u.F.F < v.F.S - v.F.F;
}
LL lsum[MXN][2];
LL rsum[MXN][2];
int main(void){
	int n, m; scanf("%d %d", &n, &m);
	rep1(i, 1, n+1) scanf("%d %d", &a[i].F.F, &a[i].F.S);
	rep1(i, 1, n+1) a[i].S = i;
	rep1(i, 1, m+1){
		int u, v; scanf("%d %d", &u, &v);
		LL v1 = a[u].F.F + a[v].F.S;
		LL v2 = a[u].F.S + a[v].F.F;
		ans[u] -= min(v1, v2);
		ans[v] -= min(v1, v2);
	}
	sort(a + 1, a + n + 1, cmp);
	rep1(i, 1, n+1){
		lsum[i][0] = lsum[i-1][0] + a[i].F.F;
		lsum[i][1] = lsum[i-1][1] + a[i].F.S;
	}
	per1(i, n, 1){
		rsum[i][0] = rsum[i+1][0] + a[i].F.F;
		rsum[i][1] = rsum[i+1][1] + a[i].F.S;
	}
	rep1(i, 1, n+1){
		int p = a[i].S;
		ans[p] += rsum[i+1][0];
		ans[p] += (LL)a[i].F.S*(n - i);
		ans[p] += lsum[i-1][1];
		ans[p] += (LL)a[i].F.F*(i-1);
	}
	rep1(i, 1, n+1) printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}