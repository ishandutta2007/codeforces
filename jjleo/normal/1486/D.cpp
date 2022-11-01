#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
int a[maxn], sum[maxn];

inline bool check(int x){
	int l = 1, r = 0, mn = 1e9, ans = -1e9;
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + (a[i] >= x ? 1 : -1);
		if(i - k >= 0) mn = min(mn, sum[i - k]);
		ans = max(ans, sum[i] - mn);
	}
	return ans > 0;
}


int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int l = 1, r = n, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}