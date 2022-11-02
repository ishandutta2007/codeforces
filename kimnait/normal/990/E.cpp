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
bitset<MAX>ck;
int pre[MAX];
LL a[MAX];
int main(void){
	DRIII(n, m, k);
	rep(i, m){
		DRI(v); ck[v] = 1;
	}
	int cp = -1;
	rep(i, n){
		if(!ck[i]) cp = i;
		pre[i] = cp;
	}
	rep1(i, 1, k+1) scanf("%lld", a + i);
	if(ck[0]){
		puts("-1"); return 0;
	}
	LL ans = INFF;
	rep1(i, 1, k+1){
		cp = 0;
		int cnt = 0;
		while(1){
			int np = cp + i - 1;
			cnt++;
			if(np >= n-1){
				ans = min(ans, a[i]*cnt);
				break;
			}
			np++;
			if(pre[np] == cp) break;
			cp = pre[np];
		}
	}


	if(ans == INFF) ans = -1;
	printf("%lld\n", ans);
	return 0;
}