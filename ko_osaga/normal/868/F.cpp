#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MAXN = 100005;
typedef long long lint;

int n, k, a[100005];
lint dp[21][100005];

pi cnt[100005];

int fuck[MAXN];


lint cost(int s, int e){
	if(s > e) return 0;
	lint ret = 0;
	for(int i=s; i<=e; i++){
		auto st = lower_bound(cnt, cnt + n, pi(a[i], s));
		auto ed = upper_bound(cnt, cnt + n, pi(a[i], e));
		ret += ed - st;
	}
	return (ret - (e - s + 1)) / 2;
}


void dnc(int pos, int s, int e, int ps, int pe, lint val){
	int m = (s+e)/2;
	int opt = -1;
	lint lval = -1; // val = cost(pe + 1, m);
	lint rval = val; 
//	assert(val == cost(pe + 1, m));
	for(int i=min(m, pe); i>=ps; i--){
		if(i < m && dp[pos][m] >= dp[pos-1][i] + val){
			dp[pos][m] = dp[pos-1][i] + val;
			opt = i;
			lval = val;	// cost(opt + 1, m)
		}
		val += fuck[a[i]];
		fuck[a[i]]++;
	}
	assert(opt != -1);
//	assert(lval == cost(opt + 1, m));
	if(s <= m - 1){	
		for(int i=ps; i<=opt; i++) fuck[a[i]]--;	
		int nxtm = (s + m - 1) / 2;
		for(int i=m; i>nxtm; i--){
			if(opt + 1 <= i){
				fuck[a[i]]--;
				lval -= fuck[a[i]];
			}
		}
		dnc(pos, s, m-1, ps, opt, lval); // need cost(opt+1, m')
		for(int i=nxtm+1; i<=m; i++) if(opt + 1 <= i) fuck[a[i]]++;
		for(int i=ps; i<=opt; i++) fuck[a[i]]++;
	}
	for(int i=ps; i<=min(m, pe); i++) fuck[a[i]]--;
	if(m + 1 <= e){
		int nxtm = (m + 1 + e) / 2;
		for(int i=m+1; i<=nxtm; i++){	
			if(pe + 1 <= i){
				rval += fuck[a[i]];
				fuck[a[i]]++;
			}
		}
		dnc(pos, m+1, e, opt, pe, rval); // need cost(pe + 1, m'');
		for(int i=m+1; i<=nxtm; i++) if(pe + 1 <= i) fuck[a[i]]--;
	}
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		cnt[i-1]= pi(a[i], i);
	}
	sort(cnt, cnt + n);
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i=1; i<=k; i++){
		dnc(i, i, n, i-1, n, 0);
		for(int i=1; i<=n; i++) assert(fuck[i] == 0);
	}
	cout << (dp[k][n]);
}