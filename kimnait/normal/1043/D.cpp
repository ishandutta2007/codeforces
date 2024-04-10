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
const int MXN = (int)2e5 + 7;
int a[MXN], b[MXN];
int nxt[MXN], pos[MXN];
int cnt[MXN];
int main(void){
	int n, m; scanf("%d %d", &n, &m);
	rep1(i, 1, n+1) scanf("%d", a + i);
	rep1(i, 1, n+1) pos[ a[i] ] = i;
	rep1(i, 1, n) nxt[ a[i] ] = a[i+1];
	m--;
	rep1(i, 1, m+1){
		rep1(j, 1, n+1) scanf("%d", b + j);
		rep1(j, 1, n) if(nxt[ b[j] ] == b[j+1]) cnt[ pos[ b[j] ] ]++;
	}
	LL ans = n;
	rep1(i, 1, n){
		if(cnt[i] == m){
			LL num = 2;
			int p = i + 1;
			while(p < n && cnt[p] == m) p++, num++;
			i = p;
			ans += num*(num-1) / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}