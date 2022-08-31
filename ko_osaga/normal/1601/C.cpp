#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1000005;

int n, m, a[MAXN], b[MAXN];

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

lint inv(){
	vector<int> v(a, a + n);
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	lint ret= 0;
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
		ret += bit.query(n) - bit.query(a[i]);
		bit.add(a[i], 1);
	}
	for(int i = 0; i < n; i++){
		bit.add(a[i], -1);
	}
	return ret;
}

void solve(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < m; i++) scanf("%d",&b[i]);
	sort(b, b + m);
	priority_queue<int> pq;
	lint ret = 0;
	for(int i = 0; i < n; i++){
		int l = lower_bound(b, b + m, a[i]) - b;
		int r = upper_bound(b, b + m, a[i]) - b;
		if(sz(pq) && pq.top() > r){
			ret += pq.top() - r;
			pq.pop();
			pq.push(r);
		}
		pq.push(l);
	}
	ret += inv();
	printf("%lld\n", ret);
}

int main(){
	int tc; scanf("%d",&tc);
	while(tc--) solve();
}