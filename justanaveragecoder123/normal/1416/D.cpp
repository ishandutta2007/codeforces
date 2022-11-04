#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cassert>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<random>
#include<chrono>
#include<bitset>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr << #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double PI=acos(-1);
const ll INF = 1LL<<62;
const ll MINF = -(1LL<<62);

template<typename T> T getint() {
	T val=0;
	char c;
	
	bool neg=false;
	while((c=gc()) && !(c>='0' && c<='9')) {
		neg|=c=='-';
	}

	do {
		val=(val*10)+c-'0';
	} while((c=gc()) && (c>='0' && c<='9'));

	return val*(neg?-1:1);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); uniform_int_distribution<int>(0, n-1)(rng)

struct bin {
	int leaf;
	int idx;
	int l,r;
	bin *L, *R;
	bin(){}
	bin(int id) {
		leaf=true;
		idx=id;
		l=-1,r=-1;
		L=R=NULL;
	}
	bin(bin* egyik, bin* masik) {
		leaf=false;
		idx=-1;
		l=-1,r=-1;
		L=egyik;
		R=masik;
	}
};

int akt_pos=0;
int pos[200001];
void dfs(bin* root) {
	if(root->leaf) {
		root->l=akt_pos;
		root->r=akt_pos;
		pos[root->idx]=akt_pos++;
	}else {
		dfs(root->L);
		dfs(root->R);
		root->l=root->L->l;
		root->r=root->R->r;
	}
}

struct dsu {
	vector<int> par;
	vector<int> sz;
	vector<bin*> bs; 
	dsu(int n) : par(n,-1) {
		
		sz.assign(n,1);
		bs.resize(n);
		for(int i=0;i<n;++i) {
			bs[i]=new bin(i);
		}
	}
	
	int get(int x) {
		if(par[x]==-1) return x;
		return par[x]=get(par[x]);
	}
	
	void merge(int x, int y) {
		int px=get(x), py=get(y);
		if(px==py) return ;
		
		if(sz[px]>sz[py]) {
			swap(px,py);
			swap(x,y); //:) lyft
		}
		
		bs[py]=new bin(bs[py], bs[px]);
		sz[py]+=sz[px];
		par[px]=py;
	}
};

struct node {
	int mx, mx_pos;
	node() {}
	node(int pos, int val) {
		mx=val;
		mx_pos=pos;
	}
	
	node operator+(const node& masik) const {
		node res(-1,-1);
		
		if(mx>masik.mx) res=*this;
		else res=masik;
		
		return res;
	}
};

node tr[4*200001];
int arr[200001];
void build(int ind, int L, int R) {
	if(L==R) {
		tr[ind]=node(L, arr[L]);
	}else {
		build(2*ind, L, (L+R)/2);
		build(2*ind+1, (L+R)/2+1, R);
		tr[ind]=tr[2*ind]+tr[2*ind+1];
	}
}

void sett(int ind, int L, int R, int i, int to) {
	if(R<i || i<L) return ;
	if(L==R) {
		tr[ind]=node(i, to);
		return ;
	}
	sett(2*ind, L, (L+R)/2, i, to);
	sett(2*ind+1, (L+R)/2+1, R, i, to);
	tr[ind]=tr[2*ind]+tr[2*ind+1];
}

node query(int ind, int L, int R, int i, int j) {
	if(R<i || j<L) return node(-1,-1);
	if(i<=L && R<=j) return tr[ind];
	return query(2*ind, L, (L+R)/2, i, j)+query(2*ind+1, (L+R)/2+1, R, i, j);
}

int main() {
	IO;
	int n,m,q;
	cin>>n>>m>>q;
	vector<int> p(n+1);
	for(int i=1;i<=n;++i) {
		cin>>p[i];
	}
	vector<pair<int,int>> edgs(m+1);
	for(int i=1;i<=m;++i) cin>>edgs[i].xx>>edgs[i].yy;
	vector<pair<int,int>> qs(q+1);
	vector<int> van(m+1, 1);
	for(int i=1;i<=q;++i) {
		cin>>qs[i].xx>>qs[i].yy;
		if(qs[i].xx==2) {
			van[qs[i].yy]=0;
		}
	}

	dsu d(n+1);	
	for(int i=1;i<=m;++i) {
		if(van[i]==1) d.merge(edgs[i].xx, edgs[i].yy);
	}
	
	vector<bin*> ivs(q+1);
	for(int i=q;i>=1;i--) {
		if(qs[i].xx==2) {
			d.merge(edgs[qs[i].yy].xx, edgs[qs[i].yy].yy);
		}else {
			ivs[i]=d.bs[d.get(qs[i].yy)];
		}
	}
	
	for(int i=1;i<=n;++i) {
		if(d.get(i)==i) {
			dfs(d.bs[i]);
		}
	}
	
	for(int i=1;i<=n;++i) {
		arr[pos[i]]=p[i];
	}
	build(1,0,n-1);
	for(int i=1;i<=q;++i) {
		if(qs[i].xx==1) {
			node res=query(1,0,n-1,ivs[i]->l,ivs[i]->r);
			cout<<res.mx<<"\n";
			sett(1,0,n-1,res.mx_pos,0);
		}
	}
	
	
	
	return 0;
}