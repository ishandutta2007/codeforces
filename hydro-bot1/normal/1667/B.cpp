// Hydro submission #62cecaba83bf9abe0bd4d556@1657719483219
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
int n,a[maxn],cnt;
int f[maxn],ans[maxn];
ll sum[maxn],c[maxn];
struct BIT {
	int c[maxn];
	void clear() {
		for(int i = 0;i <= cnt;++ i)c[i] = -1e9;
		return ;
	}
	int lowbit(int x) {
		return x & -x;
	}
	void modify(int x,int y) {
		for(;x <= cnt;x += lowbit(x))c[x] = max(y , c[x]);
		return ;
	}
	int query(int x) {
		int ans = -1e9;
		for(;x;x -= lowbit(x))ans = max(ans , c[x]);
		return ans;
	}
}tr1,tr2;
void work() {
	scanf("%d",&n);
	cnt = 0;
	for(int i = 1;i <= n;++ i)scanf("%d",&a[i]),sum[i] = sum[i - 1] + a[i],c[++ cnt] = sum[i];
	c[++ cnt] = 0;
	sort(c + 1 , c + 1 + cnt);
	cnt = unique(c + 1 , c + 1 + cnt) - c - 1;
	tr1.clear();
	tr2.clear();
	for(int i = 1;i <= cnt;++ i)f[i] = -1e9,ans[i] = 0;
	int t = lower_bound(c + 1 , c + 1 + cnt , sum[0]) - c;
	tr1.modify(t , 0);
	tr2.modify(cnt + 1 - t , 0);
	f[t] = 0;
	for(int i = 1;i <= n;++ i) {
		t = lower_bound(c + 1 , c + 1 + cnt , sum[i]) - c;
		ans[i] = max(f[t] , max(tr1.query(t - 1) + i , tr2.query(cnt - t) - i));
		tr1.modify(t , ans[i] - i);
		tr2.modify(cnt - t + 1 , ans[i] + i);
		f[t] = max(f[t] , ans[i]);
	}
	printf("%d\n",ans[n]);
	return ;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T --)work();
	return 0;
}