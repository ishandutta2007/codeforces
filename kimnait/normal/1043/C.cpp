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
int ans[MXN];
char s[MXN];
int main(void){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int cur = s[1] - 'a';
	int typ = 1;
	rep1(i, 2, n+1){
		int v = s[i] - 'a';
		if(typ == 0){
			if(v > cur) ans[i-1] = 0;
			else ans[i-1] = 1, typ = 1;
		}
		else{
			if(v > cur) ans[i-1] = 1, typ = 0;
			else ans[i-1] = 0;
		}
		cur = min(cur, v);
		if(i == n && v == cur) ans[i] = 1;
	}
	rep1(i, 1, n+1) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}