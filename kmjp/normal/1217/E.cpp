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

int N,M;
int A[202020];
pair<int,int> def={1000000001,1000000001};
template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<int,int> > val;
	
	pair<int,int> comp(pair<int,int> l,pair<int,int> r){
		if(l.second<=r.first) return l;
		if(r.second<=l.first) return r;
		if(l.first<=r.first) return {l.first,r.first};
		return {r.first,l.first};
	}
	SegTree_Pair(){
		val.resize(NV*2,def);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]={v,1000000001};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<18> st[12];


void update(int cur) {
	int i;
	int v=A[cur];
	FOR(i,10) {
		if(v%10) {
			st[i].update(cur,A[cur]);
		}
		else {
			st[i].update(cur,1000000000);
		}
		v/=10;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d",&A[i]);
		update(i);
	}
	while(M--) {
		int L,R;
		scanf("%d%d%d",&i,&L,&R);
		if(i==1) {
			L--;
			A[L]=R;
			update(L);
		}
		else {
			L--;
			int ret=2000000001;
			FOR(i,10) {
				auto p=st[i].getval(L,R);
				if(p.second<1000000000) ret=min(ret,p.first+p.second);
			}
			
			if(ret>=2000000000) ret=-1;
			_P("%d\n",ret);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}