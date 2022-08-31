#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXT = 7000000;
const int mod = 1e9 + 7;
using lint = long long;
using pi = pair<int, int>;

struct node{
	int l, r, cnt;
}tree[MAXT]; int piv; 

int newnode(){ return ++piv; }

int q;

void add(int x, int d, int p, int v){
	tree[p].cnt += v;
	if(d == -1){
		return;
	}
	if((x >> d) & 1){
		if(!tree[p].r) tree[p].r = newnode();
		add(x, d - 1, tree[p].r, v);
	}
	else{
		if(!tree[p].l) tree[p].l = newnode();
		add(x, d - 1, tree[p].l, v);
	}
}

int query(int x, int d, int p){
	if(d == -1) return 0;
	if((x >> d) & 1){
		if(tree[p].r && tree[tree[p].r].cnt) return query(x, d - 1, tree[p].r);
		return query(x, d - 1, tree[p].l) ^ (1<<d);
	}
	else{
		if(tree[p].l && tree[tree[p].l].cnt) return query(x, d - 1, tree[p].l);
		return query(x, d - 1, tree[p].r) ^ (1<<d);
	}
}

lint ret = 0;
vector<int> cont[MAXN];
int cut;

int solve(int d, int p, int v = 0){
	if(p == 0) return 0;
	if(d == -1){
		cont[++cut].push_back(v);
		return cut;
	}
	int l = solve(d - 1, tree[p].l, v);
	int r = solve(d - 1, tree[p].r, v ^ (1 << d));
	int ptr = tree[p].l;
	if(cont[l].size() < cont[r].size()){
		ptr = tree[p].r;
		swap(l, r);
	}
	if(cont[r].size()){
		lint conn = 1e18;
		for(auto &i : cont[r]){
			conn = min(conn, query(i, d - 1, ptr) ^ (1ll << d));
		}
		ret += conn;
		for(auto &i : cont[r]) cont[l].push_back(i);
	}
	return l;
}

int n, a[MAXN];

int main(){
	scanf("%d",&n);
	newnode();
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		add(a[i], 29, 1, 1);
	}
	solve(29, 1);
	cout << ret << endl;
}