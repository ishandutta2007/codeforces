#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, sn, q;
int a[maxn], b[maxn];
vector<int> v[maxn];
int l[maxn], r[maxn];
int opt, x, y;

inline void add(int x, int y){
	for(;x <= n;x += x & -x) b[x] += y;
}

inline int query(int val){
	int sum = 0, x = 0;
	for(int i = 16;~i;i--){
		if(x + (1 << i) <= n && x + (1 << i) + sum + b[x + (1 << i)] < val) sum += b[x += 1 << i]; 
	}
	return x + 1;
}

void build(int x){
	v[x].clear();
	for(int i = l[x];i <= r[x];i++) v[x].push_back(query(a[i])), add(v[x].back(), 1);
	for(int i = 0;i < v[x].size();i++) add(v[x][i], -1);
	sort(v[x].begin(), v[x].end());
}

int main(){
	scanf("%d", &n), sn = min(n, 200);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]), a[i] = i - a[i];
		int id = i / sn;
		if(!l[id]) l[id] = i;
		r[id] = i;
	}
	for(int i = n / sn;~i;i--) build(i);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			a[x] = x - y, build(x / sn);
		}else{
			scanf("%d", &x);
			int ans = a[x], lid = (x + 1) / sn, rid = n / sn;
			if(lid >= rid) for(int i = x + 1;i <= n;i++) ans += ans >= a[i];
			else{
				for(int i = x + 1;i <= r[lid];i++) ans += ans >= a[i];
				for(int i = lid + 1;i <= rid;i++) ans += upper_bound(v[i].begin(), v[i].end(), ans) - v[i].begin(); 
				//for(int i = l[rid];i <= n;i++) ans += ans >= a[i];
			}
			printf("%d\n", ans);
		}
	} 
}