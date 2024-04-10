#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, sn;
int a[maxn];
int opt, x, y, z;
int T;
pair<int, int> b[maxn];

struct Query{
	int l, r, k, t, i;
};

inline bool operator < (Query a, Query b){
	return a.l / sn ^ b.l / sn ? a.l / sn < b.l / sn : a.r / sn ^ b.r / sn ? a.r / sn < b.r / sn : a.t < b.t;
}

vector<Query> v;
int ans[maxn], l, r, t;

const int M = 1e5;
int cnt[maxn], tot[maxn], id[maxn], L[maxn], R[maxn];

inline void add(int x){
	id[R[cnt[x]]]++;
	int pos = R[cnt[x]]--;
	tot[cnt[x]]--;
	cnt[x]++;
	tot[cnt[x]]++;
	if(tot[cnt[x]] == 1) L[cnt[x]] = R[cnt[x]] = pos;
	else L[cnt[x]] = pos;
}

inline void sub(int x){
	id[L[cnt[x]]]--;
	int pos = L[cnt[x]]++;
	tot[cnt[x]]--;
	cnt[x]--;
	tot[cnt[x]]++;
	if(tot[cnt[x]] == 1) L[cnt[x]] = R[cnt[x]] = pos;
	else R[cnt[x]] = pos;
}

inline void modify(int t){
	int x = b[t].first;
	if(l <= x && x <= r){
		sub(a[x]), add(b[t].second);
	}
	swap(b[t].second, a[x]);
}

inline int cal(int k){
	int ans = 1e9;
	int x = !id[1] ? R[0] + 1 : 1;
	for(int i = x;i <= M;i = R[id[i]] + 1){
		while(id[i] != id[x] && R[id[i]] - R[id[x]] >= k) x = R[id[x]] + 1;
		if(R[id[i]] - x + 1 >= k) ans = min(ans, id[i] - id[x]);
	}
	return ans == 1e9 ? -1 : ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sn = (int)pow(n, 2.0 / 3.0);
	while(m--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d%d", &x, &y, &z);
			v.push_back((Query){x, y, z, T, (int)v.size()});
		}else{
			scanf("%d%d", &x, &y);
			b[++T] = {x, y};
		}
	}
	sort(v.begin(), v.end());
	tot[0] = M, L[0] = 1, R[0] = M;
	l = r = 1, t = 0;
	add(a[1]);
	for(int i = 0;i < v.size();i++){
		while(l > v[i].l) add(a[--l]);
		while(r < v[i].r) add(a[++r]);
		while(l < v[i].l) sub(a[l++]);
		while(r > v[i].r) sub(a[r--]);
		while(t < v[i].t) modify(++t);
		while(t > v[i].t) modify(t--);//debug 
		ans[v[i].i] = cal(v[i].k);
	}
	for(int i = 0;i < v.size();i++) printf("%d\n", ans[i]);
}