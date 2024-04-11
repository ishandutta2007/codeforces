#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long lint;

lint sz[100005];
int pa[100005];

int find(int x){
	return pa[x] = (pa[x] == x ? x : find(pa[x]));

}

bool uni(int p, int q){
	p = find(p);
	q = find(q);
	if(p == q) return 0;
	pa[q] = p;
	sz[p] += sz[q];
	return 1;
}

int n, a[100005], q[100005];
lint r[100005], cur;
int ok[100005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++) pa[i] = i;
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) scanf("%d",&q[i]);
	for(int i=n; i; i--){
		ok[q[i]] = 1;
		sz[q[i]] = a[q[i]];
		if(ok[q[i] + 1]) uni(q[i], q[i]+1);
		if(ok[q[i] - 1]) uni(q[i], q[i] - 1);
		r[i] = cur;
		cur = max(cur, sz[find(q[i])]);
	}
	for(int i=1; i<=n; i++) printf("%lld\n", r[i]);
}