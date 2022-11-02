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
int a[MXN];
int x[MXN];
bool f[MXN];
int main(void){
	int n; scanf("%d", &n);
	rep1(i, 1, n+1) scanf("%d", a + i);
	vector<int>ans;
	rep1(i, 1, n+1){
		rep(j, i) f[j] = 1;
		bool gg = 0;
		rep1(j, 1, n+1){
			int v = a[j] - a[j-1];
			if(f[(j-1) % i] == 1){
				f[(j-1) % i] = 0;
				x[(j-1) % i] = v;
			}
			else if(x[(j - 1) % i] != v){
				gg = 1; break;
			}
		}
		if(!gg) ans.pb(i);
	}
	printf("%d\n", SZ(ans));
	rep(i, SZ(ans)) printf("%d%c", ans[i], " \n"[i == SZ(ans)-1]);
	return 0;
}