#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

struct Node{
	int son[2], sum;
}t[maxn * 60]; 

#define ls(x) (t[x].son[0])
#define rs(x) (t[x].son[1])

int cnt;

void modify(int x, int l, int r, int pos, int d){
	t[x].sum = min(t[x].sum, d);
	if(l == r) return;
	int mid = l + r >> 1;
	if(mid >= pos){
		if(!ls(x)) t[ls(x) = ++cnt].sum = 1e9;
		modify(ls(x), l, mid, pos, d);
	}else{
		if(!rs(x)) t[rs(x) = ++cnt].sum = 1e9;
		modify(rs(x), mid + 1, r, pos, d);
	}
}

int query(int x, int l, int r, int ll, int rr){
	if(!x) return 1e9;
	if(ll <= l && r <= rr) return t[x].sum;
	int mid = l + r >> 1, sum = 1e9;
	if(mid >= ll) sum = min(sum, query(ls(x), l, mid, ll, rr));
	if(mid < rr) sum = min(sum, query(rs(x), mid + 1, r, ll, rr));
	return sum;
}

int n, m;

void Modify(int l, int r, int d){
	for(;l;l -= l & -l) modify(l, 1, n, r, d); 
}

int Query(int l, int r){
	int sum = 1e9;
	for(;l <= n;l += l & -l) sum = min(sum, query(l, 1, n, 1, r));
	return sum;
}

int l[maxn], r[maxn];
vector<int> v[maxn];
int ans[maxn];

int solve(int L, int R){
	if(L > R) return 0;
	int id = Query(L, R);
	if(id == 1e9) return 0;
	return solve(L, l[id] - 1) + solve(r[id] + 1, R) + r[id] - l[id] + 1;
}

int main(){
	scanf("%d%d", &n, &m), cnt = n;
	for(int i = 1;i <= cnt;i++) t[i].sum = 1e9;
	for(int i = 1;i <= m;i++) scanf("%d%d", &l[i], &r[i]), v[r[i] - l[i] + 1].push_back(i);
	for(int i = n;i;i--){
		for(int j = 0;j < v[i].size();j++) Modify(l[v[i][j]], r[v[i][j]], v[i][j]);
		ans[i] = solve(1, n);
	}
	for(int i = 1;i <= n;i++) printf("%d\n", ans[i]);
}