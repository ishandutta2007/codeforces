#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
const int N = 100005;
const int logN = 20;
int a[N], diff[N], lft[N], rgt[N], ceillog[5 * N];
pii RMQ[logN][N], P[N];
inline pii find_max(int i, int j){
	int k = ceillog[j-i+2] - 1;
    return max(RMQ[k][i],RMQ[k][j-(1<<k)+1]);	
}
int main(){
	int m, q, k, cnt = 0, l, r;
    for(k=1;(1<<k)<5*N;k++)
      for(int i = (1<<(k-1)) + 1;i<=(1<<k);i++)
          ceillog[i] = k;
    for(int i = (1<<k);i<5*N;i++)        
        ceillog[i] = k+1;
	sd(m); sd(q); int n = m - 1;
	for(int i = 1; i <= m; i++) sd(a[i]);
	for(int i = 1; i <= n; i ++) diff[i] = abs(a[i] - a[i + 1]), P[i] = {diff[i], ++cnt};
	for(int i = n; i>= 1;i--){
		RMQ[0][i] = P[i];
		int pw = 2, halfpw = 1;
		for(int j = 1; i + pw <= n + 1; j ++, pw += pw, halfpw += halfpw){
			RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][i + halfpw]);
		}
	}
	for(int i = 1; i <= n; i++){
		// find the range in which diff[i] is maximum.
		int lo = 1, hi = i;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			if(find_max(mid, i) == P[i]) hi = mid;
			else lo = mid + 1;
		}
		lft[i] = lo;
		lo = i, hi = n;
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			if(find_max(i, mid) == P[i]) lo = mid;
			else hi = mid - 1;
		}
		rgt[i] = lo;
	}
	while(q--){
		sd(l), sd(r);
		if(r - l + 1< 2){
			printf("%d\n", 0); continue;
		}
		ll ans = 0;
		for(int i = l; i <= r - 1; i ++){
			int L = max(l, lft[i]), R = min(r - 1, rgt[i]);
			ans += (i - L + 1) * 1ll *(R + 1 - i) * 1ll * diff[i];
		}
		printf("%lld\n", ans);
	}
}