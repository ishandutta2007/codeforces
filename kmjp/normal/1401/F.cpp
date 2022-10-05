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


int R[19];
int S[19];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	SegTree_3(){
		int i;
		val.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1,int step=18) {
		if(y<x) return 0;
		if(r<=x || y<l) return 0;
		if(x<=l && r-1<=y) return val[k];
		assert(step>0);
		x=max(x,l);
		y=min(y,r-1);
		if(step && R[step]) {
			x^=(1<<step)-1;
			y^=(1<<step)-1;
			swap(x,y);
		}
		if(S[step-1]) {
			x^=1<<(step-1);
			y^=1<<(step-1);
		}
		if(x<=y) {
			return getval(x,y,l,(l+r)/2,k*2,step-1)+getval(x,y,(l+r)/2,r,k*2+1,step-1);
		}
		else {
			return val[k]-getval(y+1,(l+r)/2-1,l,(l+r)/2,k*2,step-1)-getval((l+r)/2,x-1,(l+r)/2,r,k*2+1,step-1);
		}
	}
	
	void update(int x,V v,int l=0,int r=NV,int k=1,int step=18) {
		if(step==0) {
			val[k]=v;
		}
		else {
			
			if(R[step]) x^=(1<<step)-1;
			if(S[step-1]) x^=1<<(step-1);
			
			if(x<(l+r)/2) update(x,v,l,(l+r)/2,k*2,step-1);
			else update(x,v,(l+r)/2,r,k*2+1,step-1);
			
			val[k]=val[k*2]+val[k*2+1];
		}
	}
};



int N,Q;
SegTree_3<ll,1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,1<<N) {
		scanf("%d",&x);
		st.update(i,x);
	}
	while(Q--) {
		scanf("%d",&i);
		if(i==1) {
			scanf("%d%d",&x,&k);
			x--;
			st.update(x,k);
		}
		else if(i==2) {
			scanf("%d",&x);
			R[x]^=1;
		}
		else if(i==3) {
			scanf("%d",&x);
			S[x]^=1;
		}
		else {
			scanf("%d%d",&x,&y);
			cout<<st.getval(x-1,y-1)<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}