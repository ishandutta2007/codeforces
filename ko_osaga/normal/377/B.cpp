#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, m, s;
pi a[100005];
int ans[100005];

struct student{
	int val, idx, cst;
	bool operator<(const student &s)const{
		return val < s.val;
	}
}b[100005];

int cnt[100005];

lint trial(int l){
	for(int i=1; i<=n; i++) cnt[i] = l;
	int p = n;
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	lint ret = 0;
	for(int i=m; i; i--){
		while(p > 0 && b[p].val >= a[i].first){
			pq.push({b[p].cst, b[p].idx});
			p--;
		}
		if(pq.empty()){
			return 1e18;
		}
		else{
			auto x = pq.top();
			pq.pop();
			ans[a[i].second] = x.second;
			cnt[x.second]--;
			ret += x.first;
			x.first = 0;
			if(cnt[x.second] > 0) pq.push(x);
		}
	}
	return ret;
}

int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1; i<=m; i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i].val);
		b[i].idx = i;
	}
	for(int i=1; i<=n; i++) scanf("%d",&b[i].cst);
	sort(a+1, a+1+m);
	sort(b+1, b+1+n);
	int st = 0, ed = max(n, m);
	while(st != ed){
		int m = (st+ed)/2;
		if(trial(m) <= s) ed = m;
		else st = m+1;
	}
	if(trial(st) > s){
		puts("NO");
	}
	else{
		puts("YES");
		for(int i=1; i<=m; i++) printf("%d ", ans[i]);
	}
}