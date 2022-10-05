#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int L[202020],R[202020];
int A[202020],B[202020],C[202020];
ll ret;
int idx,idy;

set<pair<int,int> > Ls,Rs;
vector<pair<int,int> > events;
vector<int> P;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<ll,1<<20> ST;
map<int,int> MM;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		if(L[i]<R[i]) {
			events.push_back({L[i],i+300000});
			events.push_back({R[i],i+300000});
		}
		P.push_back(L[i]);
	}
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		if(A[i]<B[i]) {
			events.push_back({A[i],i});
			events.push_back({B[i],i});
		}
		P.push_back(A[i]);
		P.push_back(B[i]);
	}
	sort(ALL(events));
	sort(ALL(P));
	P.erase(unique(ALL(P)),P.end());
	
	FORR(e,events) {
		int pos=e.first;
		r = e.second;
		if(r<300000) {
			if(A[r]==pos) {
				if(Rs.size()) {
					ll len = min(B[r],Rs.rbegin()->first)-pos;
					if(ret<len*C[r]) {
						ret=len*C[r];
						idx=Rs.rbegin()->second;
						idy=r;
					}
				}
			}
			else if(B[r]==pos) {
				if(Ls.size()) {
					ll len = pos-max(A[r],Ls.begin()->first);
					if(ret<len*C[r]) {
						ret=len*C[r];
						idx=Ls.begin()->second;
						idy=r;
					}
				}
				x = lower_bound(ALL(P),A[r])-P.begin();
				y = lower_bound(ALL(P),B[r])-P.begin();
				ll len = ST.getval(x,y);
				if(ret<len*C[r]) {
					ret=len*C[r];
					idx=MM[len];
					idy=r;
				}
			}
		}
		else {
			r-=300000;
			if(L[r]==pos) {
				if(Rs.empty() || Rs.rbegin()->first<R[r]) {
					Ls.insert({L[r],r});
					Rs.insert({R[r],r});
				}
			}
			else {
				if(Rs.count({R[r],r})) {
					l = lower_bound(ALL(P),L[r])-P.begin();
					ST.update(l,R[r]-L[r]);
					MM[R[r]-L[r]]=r;
					
					Ls.erase({L[r],r});
					Rs.erase({R[r],r});
				}
			}
		}
	}
	
	if(ret) {
		cout<<ret<<endl;
		cout<<(idx+1)<<" "<<(idy+1)<<endl;
	}
	else {
		cout<<0<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}