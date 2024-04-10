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

int N;
string S;

static ll const def=1<<22;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=0;
		for(i=NV-1;i>=1;i--) ma[i]=min(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};

SegTree_3<int,1<<21> st,rst;
char R[1<<21];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int cur=0;
	int prev=0;
	FORR(c,S) {
		if(c=='R') {
			cur++;
		}
		else if(c=='L') {
			if(cur>0) cur--;
		}
		else if(R[cur] != c) {
			if(R[cur]=='(') {
				st.update(cur,1<<21,-1);
				rst.update(cur,1<<21,1);
			}
			else if(R[cur]==')') {
				st.update(cur,1<<21,1);
				rst.update(cur,1<<21,-1);
			}
			R[cur]=c;
			if(R[cur]=='(') {
				st.update(cur,1<<21,1);
				rst.update(cur,1<<21,-1);
			}
			else if(R[cur]==')') {
				st.update(cur,1<<21,-1);
				rst.update(cur,1<<21,1);
			}
			
			if(st.getval((1<<21)-2,(1<<21)-1)!=0) {
				prev=-1;
			}
			else if(st.getval(0,(1<<21)-1)<0) {
				prev=-1;
			}
			else {
				prev=-rst.getval(0,(1<<21)-1);
			}
			
		}
		_P("%d ",prev);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}