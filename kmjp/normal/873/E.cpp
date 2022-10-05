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

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(0,0);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<13> st;


int N;
vector<pair<int,int>> V;
int ret[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V.push_back({0,-1});
	FOR(i,N) cin>>x, V.push_back({x,i});
	sort(ALL(V));
	reverse(ALL(V));
	
	FOR(i,N) {
		st.update(i,V[i].first-V[i+1].first);
	}
	
	int d12=-1,d23=0,d34=0;
	int mx,my,mz;
	for(x=1;x<=N;x++) {
		
		for(y=1;x+y<N;y++) if(x<=2*y && y<=2*x) {
			int zmin=(max(x,y)+1)/2;
			int zmax=min(N-x-y,min(x,y)*2);
			if(zmin>zmax) continue;
			
			
			auto dm=st.getval(x+y+zmin-1,x+y+zmax);
			
			if(V[x-1].first-V[x].first>d12 ||
			   (V[x-1].first-V[x].first==d12 && V[x+y-1].first-V[x+y].first>d23) ||
			   (V[x-1].first-V[x].first==d12 && V[x+y-1].first-V[x+y].first==d23 && dm.first>d34)) {
				d12=V[x-1].first-V[x].first;
				d23=V[x+y-1].first-V[x+y].first;
				d34=dm.first;
				mx=x;
				my=y;
				mz=dm.second-(x+y)+1;
			}
		}
	}
	
	FOR(i,N) {
		if(i<mx) ret[V[i].second]=1;
		else if(i<mx+my) ret[V[i].second]=2;
		else if(i<mx+my+mz) ret[V[i].second]=3;
		else ret[V[i].second]=-1;
	}
	FOR(i,N) _P("%d%c",ret[i],(i==N-1)?'\n':' ');
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}