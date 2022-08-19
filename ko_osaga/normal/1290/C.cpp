#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 600005;

struct node{
	int rootVal;
	int cnt0, cnt1;
	node(){
		rootVal = -1;
		cnt0 = 1, cnt1 = 0;
	}
};

struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int dap;

struct disj2{
	node val[MAXN];
	int pa[MAXN];
	void update(int x, int v){
		if(val[x].rootVal == -1){
			dap += min(val[x].cnt1, val[x].cnt0) * v;
		}
		if(val[x].rootVal == 0){
			dap += val[x].cnt1 * v;
		}
		if(val[x].rootVal == 1){
			dap += val[x].cnt0 * v;
		}
	}
	void init(int n){
		iota(pa, pa + n + 1, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	void assign(int x, int v){
		int nx = find(x);
		if(val[nx].rootVal != -1) return;
		update(nx, -1);
		if(disj.find(nx) != disj.find(x)) v ^= 1;
		val[nx].rootVal = v;
		update(nx, +1);
	}
	bool uni(int p, int q, int v){
		int np = find(p), nq = find(q);
		if(disj.find(np) != disj.find(p)) v ^= 1;
		if(disj.find(nq) != disj.find(q)) v ^= 1;
		if(np == nq) return 0;
		if(val[np].rootVal > val[nq].rootVal) swap(np, nq);
		update(np, -1);
		update(nq, -1);
		if(v) swap(val[np].cnt0, val[np].cnt1);
		val[nq].cnt0 += val[np].cnt0;
		val[nq].cnt1 += val[np].cnt1;
		pa[np] = nq;
		update(nq, +1);
		return 1;
	}
}disj2;

int n, k;
char str[MAXN];
vector<int> num[MAXN];

int main(){
	scanf("%d %d %s",&n,&k,str);
	for(int i=0; i<n; i++) str[i] ^= 1;
	for(int i=0; i<k; i++){
		int c; scanf("%d",&c);
		for(int j=0; j<c; j++){
			int v; scanf("%d",&v);
			num[v - 1].push_back(i);
		}
	}
	disj.init(k+k);
	disj2.init(k);
	for(int i=0; i<n; i++){
		if(sz(num[i]) == 1){
			disj2.assign(num[i][0], str[i] & 1);
		}
		else if(sz(num[i]) == 2){
			if(str[i] & 1){
				disj.uni(num[i][0], num[i][1] + k);
				disj.uni(num[i][1], num[i][0] + k);
			}
			else{
				disj.uni(num[i][0] + 0, num[i][1] + 0);
				disj.uni(num[i][0] + k, num[i][1] + k);
			}
			disj2.uni(num[i][0], num[i][1], str[i] & 1);
		}
		printf("%d\n", dap);
	}
}