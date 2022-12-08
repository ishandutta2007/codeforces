#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
 
int n, dat[55];
int cd[33554432];
int pre[30][1250005], nxt[30][1250005], csum, rsum;
int tot, ans[2][35];
int cmask = -1, ccnt0, cx;
 
int gmask;
void dfs(int id, int beg0, int beg1, int cnt0, int cur)
{
	if(id == n) {
		if(beg0 == -1 || beg1 == -1) return;
		int cur0 = dat[beg1] + cur, cur1 = dat[beg0] + csum - cur;
		int x = max((cur1 + rsum - cur0) / 2, 0);
		if(pre[n - cnt0][x] != -1) {
			int ctot = max(cur0 + pre[n - cnt0][x], cur1 + rsum - pre[n - cnt0][x]);
			if(tot > ctot) {
				tot = ctot;
				cmask = gmask;
				ccnt0 = cnt0;
				cx = pre[n - cnt0][x];
			}
		}
		if(nxt[n - cnt0][x] != -1) {
			int ctot = max(cur0 + nxt[n - cnt0][x], cur1 + rsum - nxt[n - cnt0][x]);
			if(tot > ctot) {
				tot = ctot;
				cmask = gmask;
				ccnt0 = cnt0;
				cx = nxt[n - cnt0][x];
			}
		}
		return;
	}
	gmask ^= 1 << id;
	dfs(id + 1, beg0 == -1 ? id : beg0, beg1, cnt0 + 1, cur + dat[id]);
	gmask ^= 1 << id;
	dfs(id + 1, beg0, beg1 == -1 ? id : beg1, cnt0, cur);
}
 
int main()
{
	scanf("%d", &n);
	rep(i, 2 * n) scanf("%d", &dat[i]);
	sort(dat, dat + 2 * n);
	
	tot += dat[0];
	for(int i = n; i < 2 * n; i ++) tot += dat[i];
	rep(i, n) ans[0][i] = dat[i];
	rep(i, n) ans[1][i] = dat[2 * n - 1 - i];
	
	rep(i, n) cd[1 << i] = dat[i + n];
	rep(i, 1 << n) cd[i] = cd[i & -i] + cd[i ^ (i & -i)];
	
	for(int j = 0; j <= n; j ++) rep(i, n * 50000 + 1) pre[j][i] = nxt[j][i] = -1;
	rep(i, 1 << n) pre[__builtin_popcount(i)][cd[i]] = nxt[__builtin_popcount(i)][cd[i]] = cd[i];
	for(int j = 0; j <= n; j ++) {
		rep1(i, n * 50000) if(pre[j][i] == -1) pre[j][i] = pre[j][i - 1];
		for(int i = n * 50000 - 1; i >= 0; i --) if(nxt[j][i] == -1) nxt[j][i] = nxt[j][i + 1];
	}
	rsum = cd[(1 << n) - 1];
	rep(i, n) csum += dat[i];
	
	dfs(0, -1, -1, 0, 0);
	
	if(cmask != -1) {
		int p0 = 0, p1 = n - 1;
		rep(i, n) if(cmask >> i & 1) ans[0][p0 ++] = dat[i];
		else ans[1][p1 --] = dat[i];
		
		ccnt0 = n - ccnt0;
		rep(i, 1 << n) if(__builtin_popcount(i) == ccnt0 && cd[i] == cx) {
			rep(j, n) if(i >> j & 1) ans[0][p0 ++] = dat[j + n];
			else ans[1][p1 --] = dat[j + n];
			break;
		}
	}
	
	rep(i, 2) {
		rep(j, n) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}