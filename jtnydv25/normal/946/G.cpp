#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 200005;
int a[N], dp[2][N];

int perm[N];
bool cmp(int i, int j){
	return a[i] < a[j];
}
int n;
struct segtree{
	int tree[N << 2];
	void update(int i, int x, int s = 1, int e = n, int ind = 1){
		if(s > i || e < i) return;
		tree[ind] = max(tree[ind], x);
		if(s == e) return;
		int mid = (s + e) >> 1;
		update(i, x, s, mid, ind << 1);
		update(i, x, mid + 1, e, ind << 1 | 1);
	}
	int get(int l, int r, int s = 1, int e = n, int ind = 1){
		if(s > r || e < l || l > r)return 0;
		if(s >= l && e <= r) return tree[ind];
		int mid = (s + e) >> 1;
		return max(get(l, r, s, mid, ind << 1), get(l, r, mid + 1, e, ind << 1 | 1));
	}
} st[3];

int invperm[N];

int getInd(int x){
	int lo = 0, hi = n;
	while(lo < hi){
		int mid = (lo + hi + 1) >> 1;
		if(a[perm[mid]] <= x) lo = mid;
		else hi = mid - 1;
	}

	return lo;
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]), a[i] += n - (i - 1), perm[i] = i;
	sort(perm + 1, perm + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		invperm[perm[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dp[0][i] = st[0].get(1, getInd(a[i])) + 1;
		if(i >= 3) dp[1][i] = st[1].get(1, getInd(a[i] + 1)) + 1;

		if(i >= 3){
			dp[1][i] = max(dp[1][i], st[2].get(1, getInd(a[i])) + 1);
			// trace(dp[1][i]);
		}
		if(dp[1][i] == 1) dp[1][i] = 0;
		st[0].update(invperm[i], dp[0][i]);
		if(i >= 2) st[1].update(invperm[i - 1], dp[0][i - 1]);
		if(i >= 3) st[2].update(invperm[i], dp[1][i]);
		ans = max(ans, dp[1][i]);
		ans = max(ans, dp[0][i]);
	}
	printf("%d\n", max(0, n - 1 - ans));
}