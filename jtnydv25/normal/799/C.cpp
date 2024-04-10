#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int N = 2e5;
const int inf = 1e9;
pii price[N];
vector<pii> vec[2];
vector<int> maxv[2];
int b[N], p[N];
int tree[3 * N];
void update(int s, int e, int ind, int i, int x){
	if(s > i || e < i) return;
	if(s == i && e == i){
		tree[ind] = max(tree[ind], x);
		return;
	}
	int mid = (s + e) >> 1;
	update(s, mid, 2 * ind, i, x);
	update(mid + 1, e, 2 * ind + 1, i, x);
	tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
}
int getmax(int s, int e, int ind, int l, int r){
	if(r < l || s > r || l > e) return 0;
	if(s >= l && e <= r) return tree[ind];
	int mid = (s + e) >> 1;
	return max(getmax(s, mid, 2 * ind, l, r), getmax(mid + 1, e, 2 * ind + 1, l, r));
}
int mx = 100005;
int main(){
	int t = 1, n, c, d;
	// sd(t);
	int ans1 = 0, ans2 = 0;
	sd(n); sd(c); sd(d);
	char X;
	for(int i = 1; i <= n; i++){
		cin >> b[i] >> p[i] >> X;
		vec[X - 'C'].pb(mp(p[i], b[i]));
	}
	int ans = 0;
	int x = 0, y = 0;
	for(int i = 0; i < vec[0].size(); i++){
		int add = getmax(1, mx, 1, 1, c - vec[0][i].F);
		if(add) ans = max(ans, vec[0][i].S + add);
		update(1, mx, 1, vec[0][i].F, vec[0][i].S);
		if(vec[0][i].F <= c) x = max(x, vec[0][i].S);
	}
	memset(tree, 0, sizeof tree);
	for(int i = 0; i < vec[1].size(); i++){
		int add = getmax(1, mx, 1, 1, d - vec[1][i].F);
		if(add) ans = max(ans, vec[1][i].S + add);
		update(1, mx, 1, vec[1][i].F, vec[1][i].S);
		if(vec[1][i].F <= d) y = max(y, vec[1][i].S);
	}
	if(x > 0 && y > 0) ans = max(ans, x + y);
	printf("%d\n", ans);
}