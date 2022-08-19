#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1000005;

vector<int> toAdd[MAXN], interv[MAXN];
int dp[MAXN];

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i = x; i < MAXN; i += i & -i) tree[i] += v;
	}
	int query(int x){
		int ret = 0;
		for(int i = x; i; i -= i & -i )ret += tree[i];
		return ret;
	}
}bit;

int main(){
	int n, d;
	scanf("%d %d",&n,&d);
	vector<pi> pnt, intv;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int s, a; scanf("%d %d",&s,&a);
		if(d > s) continue;
		a = max(a, d);
		if(a <= s) pnt.emplace_back(a, s);
		else intv.emplace_back(s, a);
		v.push_back(a);
		v.push_back(s);
	}
	v.push_back(-1);
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for(auto &[x, y] : pnt){
		x = lower_bound(all(v), x) - v.begin();
		y = lower_bound(all(v), y) - v.begin();
		toAdd[y + 1].emplace_back(x);
	}
	for(auto &[x, y] : intv){
		x = lower_bound(all(v), x) - v.begin();
		y = lower_bound(all(v), y) - v.begin();
		interv[y].emplace_back(x);
	}
	dp[0] = sz(pnt);
	for(int i = 1; i < MAXN; i++){
		dp[i] = dp[i - 1];
		for(auto &v : toAdd[i]){
			bit.add(v, 1);
		}
		for(auto &j : interv[i]){
			dp[i] = max(dp[i], dp[j] + 1 - (bit.query(i) - bit.query(j)));
		}
	}
	cout << dp[MAXN - 1] << endl;
}