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

template<int NV> class SegTree_Lazy {
public:
	vector<int> val,to;
	SegTree_Lazy(){
		val.resize(NV*2,1);
		to.resize(NV*2,1);
		
		for(int i=NV-1;i>=1;i--) to[i]=to[i*2]+to[i*2+1];
	};

	int getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return to[k];
		return val[k]*(getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]*=-1;
			to[k]*=-1;
		}
		else if(l < y && x < r) {
			update(x,y,l,(l+r)/2,k*2);
			update(x,y,(l+r)/2,r,k*2+1);
			to[k]=val[k]*(to[k*2]+to[k*2+1]);
		}
	}
};
SegTree_Lazy<1<<20> st;

int N,Q;
int P[202020];
vector<int> E[202020];
int C[202020];

int L[202020],R[202020];
int eid;

void EulerTour(int cur,int pre=-1) {
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=pre) EulerTour(*it,cur);
	R[cur]=eid;
}

void solve() {
	int i,j,k,l,r,x,y; char s[30];
	
	scanf("%d",&N);
	for(i=1;i<N;i++) {
		scanf("%d",&P[i]);
		P[i]--;
		E[P[i]].push_back(i);
	}
	EulerTour(0);
	FOR(i,N) {
		scanf("%d",&x);
		if(x==0) st.update(L[i],L[i]+1);
	}
	scanf("%d",&Q);
	while(Q--) {
		scanf("%s %d",s,&x);
		x--;
		if(s[0]=='p') {
			st.update(L[x],R[x]);
		}
		else {
			int A=R[x]-L[x];
			int D=st.getval(L[x],R[x]);
			_P("%d\n",(A+D)/2);
			
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}