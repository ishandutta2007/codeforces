#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int Q;
int X[303030],Y[303030];
ll cur;
map<pair<int,int>,int> m;
ll ret[(1<<19)+5];

template<int um> class UF_pop {
	public:
	vector<int> par,rank,Xs,Ys; vector<vector<int>> hist;
	UF_pop() {par=rank=Xs=Ys=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;
		for(int i=0;i<300000;i++) Xs[i]=1,Ys[i+300000]=1;
	}
	void reinit() {int i; FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2]; Xs[a[0]]=a[3]; Ys[a[0]]=a[4];
			par[a[5]]=a[6]; rank[a[5]]=a[7]; Xs[a[5]]=a[8]; Ys[a[5]]=a[9];
			cur-=1LL*(Xs[a[0]]+Xs[a[5]])*(Ys[a[0]]+Ys[a[5]]);
			cur+=1LL*Xs[a[0]]*Ys[a[0]]+1LL*Xs[a[5]]*Ys[a[5]];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],Xs[x],Ys[x],y,par[y],rank[y],Xs[y],Ys[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
		cur-=1LL*Xs[x]*Ys[x]+1LL*Xs[y]*Ys[y];
		cur+=1LL*(Xs[x]+Xs[y])*(Ys[x]+Ys[y]);
		Xs[x]=Xs[y]=Xs[x]+Xs[y];
		Ys[x]=Ys[y]=Ys[x]+Ys[y];
	}
};
UF_pop<606060> uf;

template<int NV> class SegTree_2 {
public:
	vector<vector<pair<int,int>>> ev;
	SegTree_2(){ev.resize(NV*2);};
	
	void update(int x,int y, pair<int,int> e,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			ev[k].push_back(e);
		}
		else if(l < y && x < r) {
			update(x,y,e,l,(l+r)/2,k*2);
			update(x,y,e,(l+r)/2,r,k*2+1);
		}
	}
	
	void dfs(int k=1,int L=0,int R=NV) {
		int num=0;
		FORR(e,ev[k]) {
			if(uf[e.first]!=uf[e.second]) {
				uf(e.first,e.second);
				num++;
			}
		}
		if(L+1==R) {
			ret[L+1]=cur;
		}
		else {
			dfs(k*2,L,(L+R)/2);
			dfs(k*2+1,(L+R)/2,R);
		}
		while(num--) uf.pop();
	}
};
SegTree_2<1<<19> st;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		Y[i]+=300000;
		if(m.count({X[i],Y[i]})) {
			st.update(m[{X[i],Y[i]}],i,{X[i],Y[i]});
			m.erase({X[i],Y[i]});
		}
		else {
			m[{X[i],Y[i]}]=i;
		}
	}
	FORR(e,m) {
		st.update(e.second,Q+1,e.first);
	}
	st.dfs();
	
	FOR(i,Q) cout<<ret[i+1]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}