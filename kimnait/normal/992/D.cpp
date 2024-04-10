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
const int MAX = 2e5+7;
int n;
LL k;
LL a[MAX];
int pre[MAX];
const LDB inff = 2e18;
void init(){
	scanf("%d %lld", &n, &k);
	rep1(i, 1, n+1) scanf("%lld", a + i);
	int cp = n+1; 
	per1(i, n, 1){
		pre[i] = cp;
		if(a[i] != 1) cp = i;
	}
	return ;
}
void sol(){
	LL ans = 0;

	rep1(i, 1, n+1){
		if(k == 1) ans++;
		LL v1 = a[i], v2 = a[i];
		int np = pre[i], cp = i;
		while(cp != n+1){
			LL num = np - cp - 1;
			if(v1 % k == 0 && v1 / k > v2 && v1 / k <= v2 + num) ans++;
			v2 += num;
			if(np == n+1) break;
			if((LDB)v1*a[np] > inff) break;
			v1 *= a[np];
			v2 += a[np];
			if(v1 % v2 == 0 && v1 / v2 == k) ans++;
			cp = np;
			np = pre[cp];
		}
	}

	printf("%lld\n", ans);
	return ;
}
int main(void){
	init();
	sol();
	return 0;
}