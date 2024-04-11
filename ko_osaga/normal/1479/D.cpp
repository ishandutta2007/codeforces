#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
const int MAXN = 300010;
const int MX=300010;

int n, C[MX];
vector<int> G[MX];

int in[MX], out[MX];
int dep[MX], anc[20][MX];

void dfs(int v, int p=0, int d=0){
    static int now=0;
    in[v]=++now; anc[0][v]=p; dep[v]=d++;
    for(int x:G[v]) if(x!=p) dfs(x,v,d);
    out[v]=++now;
}

int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=19; i>=0; i--) if(dep[u]-(1<<i)>=dep[v])
        u=anc[i][u];
    if(u==v) return u;
    for(int i=19; i>=0; i--) if(anc[i][u]!=anc[i][v])
        u=anc[i][u], v=anc[i][v];
    return anc[0][u];
}

using hsh = unsigned long long;
hsh a[MAXN];

struct {
    struct node { 
    	int val, l, r; 
    	hsh hashSum;
    } tree[20000000]={};
    int root[MX*2]={}, bck=0;
    int make(int v, int pos, int df, int s=1, int e=300000){
        if(pos<s || e<pos) return v;
        node &nd=tree[++bck]; nd=tree[v]; v=bck;
        nd.val+=df;
        nd.hashSum ^= a[pos];
        if(s==e) return v;
        nd.l = make(nd.l, pos, df, s, (s+e)/2);
        nd.r = make(nd.r, pos, df, (s+e)/2+1, e);
        return v;
    }
    int most(int nd1, int nd2, int s=1, int e=300000){
        if(s==e) return s;
        int l1=tree[nd1].l, r1=tree[nd1].r;
        int l2=tree[nd2].l, r2=tree[nd2].r;
        int lval=tree[l2].val-tree[l1].val;
        int rval=tree[r2].val-tree[r1].val;
        if(lval==rval) return -1;
        if(lval>rval) return most(l1, l2, s, (s+e)/2);
        if(lval<rval) return most(r1, r2, (s+e)/2+1, e);
        return -1;
    }
    int count(int nd1, int nd2, int c, int s=1, int e=300000){
        if(c<s || e<c) return 0;
        if(s==e) return tree[nd2].val-tree[nd1].val;
        return count(tree[nd1].l, tree[nd2].l, c, s, (s+e)/2) + count(tree[nd1].r, tree[nd2].r, c, (s+e)/2+1, e);
    }
    int trace(int nd1, int nd2, int s, int e, int ps = 1, int pe = 300000){
    	if(e < ps || pe < s) return -1;
    	if(s <= ps && pe <= e){
    		if(tree[nd1].hashSum == tree[nd2].hashSum) return -1;
    		while(ps != pe){
    			int pm = (ps+pe)/2;
    			if(tree[tree[nd1].l].hashSum != tree[tree[nd2].l].hashSum){
    				nd1 = tree[nd1].l;
    				nd2 = tree[nd2].l;
    				pe = pm;
				}
				else{
					nd1 = tree[nd1].r;
					nd2 = tree[nd2].r;
					ps = pm + 1;
				}
			}
			return ps;
		}
		int pm = (ps+pe)/2;
		int m1 = trace(tree[nd1].l, tree[nd2].l, s, e, ps, pm);
		if(~m1) return m1;
		return trace(tree[nd1].r, tree[nd2].r, s, e, pm+1, pe);
	}
} PST;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
lint randint(lint lb, lint ub){ return uniform_int_distribution<lint>(lb, ub)(rng); }

void init(){
    dfs(1);
    for(int i = 1; i <= n; i++){
    	a[i] = randint(0, (1ll << 63) - 1);
	}
    for(int j=1; j<20; j++) for(int i=1; i<=n; i++)
        anc[j][i]=anc[j-1][anc[j-1][i]];
    vector<pair<int, int>> V;
    for(int i=1; i<=n; i++)
        V.push_back({in[i], C[i]}), V.push_back({out[i], -C[i]});
    sort(V.begin(), V.end());

    for(int i=1; i<=2*n; i++){
        if(i!=V[i-1].first){ cout<<"WTF\n"; exit(1); }
        int c=V[i-1].second, df=(c<0 ? -1 : 1); c=abs(c);
        PST.root[i] = PST.make(PST.root[i-1], c, df);
    }
}

int count(int v, int p, int c){
    // v p , c 
    // p can be 0
    // v can be p

    if(c==-1 || v==p) return 0;

    int l=in[p], r=in[v];
    int nd1=PST.root[l], nd2=PST.root[r];
    return PST.count(nd1, nd2, c);
}

int solve(int u, int v, int l, int r){
    int p=lca(u,v), q=anc[0][p];
    auto witness = [&](int x){
    //	printf("%d on [%d, %d]\n", x, l, r);
    	if(!(l <= x && x <= r)) return false;
		int c = count(u, p, x) + count(v, q, x);
	//	printf("count on %d %d = %d\n", u, v, x);
		return c % 2 == 1;
	};
	if(witness(C[p])) return C[p];
	int nd1, nd2;
	{
		int l = in[u], r = in[v];
		if(l > r) swap(l, r);
		nd1=PST.root[l], nd2=PST.root[r];
	}
	if(C[p] < l || C[p] > r){
		int w = PST.trace(nd1, nd2, l, r);
		if(witness(w)) return w;
	}
	else{
		if(C[p] > l){
			int w = PST.trace(nd1, nd2, l, C[p] - 1);
			if(witness(w)) return w;
		}
		if(C[p] < r){
			int w = PST.trace(nd1, nd2, C[p] + 1, r);
			if(witness(w)) return w;
		}
	}
    return -1;
}

vector<int> getFruits(vector<int> _C, vector<int> U, vector<int> V, int Q){
	int N = _C.size();
    n=N;
    for(int i=0; i<n; i++) C[i+1]=_C[i];
    for(int i=0; i<=n-2; i++){
        G[U[i]].push_back(V[i]);
        G[V[i]].push_back(U[i]);
    }

    init();
    
    vector<int> R(Q, -1);

    for(int i=0; i<Q; i++){
    	int s, e, x, y;
    	scanf("%d %d %d %d",&s,&e,&x,&y);
    	printf("%d\n", solve(s, e, x, y));
	}

	return R;
}

int main(){
	int n, q; scanf("%d %d",&n,&q);
	vector<int> c(n); for(auto &i : c) scanf("%d",&i);
	vector<int> u(n-1), v(n-1);
	for(int i=0; i<n-1; i++) scanf("%d %d",&u[i],&v[i]);
	getFruits(c, u, v, q);
}