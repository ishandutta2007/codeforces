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

int N,K,Q;
ll B[101010];

static ll const def=1<<30;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,mi;
	SegTree_3(){
		val.resize(NV*2,def);
		mi.resize(NV*2,def);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return mi[k];
		if(val[k]!=-1) return val[k];
		return min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=mi[k]=v;
		}
		else if(l < y && x < r) {
			if(val[k]!=-1) {
				val[k*2]=val[k*2+1]=val[k];
				mi[k*2]=mi[k*2+1]=val[k];
				val[k]=-1;
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mi[k]=min(mi[k*2],mi[k*2+1]);
		}
	}
};

SegTree_3<int,1<<20> st1,st2;
int T[101010],L[101010],R[101010],X[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>B[i], st1.update(i,i+1,B[i]),st1.update(i+N,i+N+1,B[i]);
	
	cin>>Q;
	vector<int> V;
	V.push_back(0);
	V.push_back(N*K);
	FOR(i,Q) {
		cin>>T[i]>>L[i]>>R[i];
		L[i]--;
		V.push_back(L[i]);
		V.push_back(R[i]);
		if(T[i]==1) cin>>X[i];
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	FOR(i,V.size()-1) {
		if(V[i+1]-V[i]>=N) {
			x=st1.getval(0,N);
		}
		else {
			y = V[i]/N*N;
			x=st1.getval(V[i]-y,V[i+1]-y);
		}
		st2.update(i,i+1,x);
	}
	
	FOR(i,Q) {
		x=lower_bound(ALL(V),L[i])-V.begin();
		y=lower_bound(ALL(V),R[i])-V.begin();
		if(T[i]==1) {
			st2.update(x,y,X[i]);
		}
		else {
			cout<<st2.getval(x,y)<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}