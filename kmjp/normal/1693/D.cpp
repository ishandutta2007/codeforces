#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,P[202020];
int RM[202020];
int LL[202020];

template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<18;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
	void reinit(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-(1<<18);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
	void reinit(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_mi<int,1<<20> stmi;
SegTree_ma<int,1<<20> stma;

int RR[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		RR[i]=1<<20;
	}
	FOR(r,2) {
		stmi.reinit();
		for(i=N-1;i>=0;i--) {
			RM[i]=stmi.getval(P[i],N+1);
			stmi.update(P[i],i);
		}
		stma.reinit();
		vector<pair<int,int>> cand;
		FOR(i,N) {
			LL[i]=stma.getval(0,P[i]);
			stma.update(P[i],i);
			cand.push_back({P[i],i});
		}
		sort(ALL(cand));
		stma.reinit();
		
		FORR2(a,i,cand) {
			x=RM[i];
			stma.update(i,LL[i]);
			if(x>=N) continue;
			if(stma.getval(x+1,N)<=x) continue;
			y=N-1;
			for(j=20;j>=0;j--) if(y-(1<<j)>x) {
				if(stma.getval(x+1,y-(1<<j)+1)>x) {
					y-=1<<j;
				}
			}
			RR[i]=min(RR[i],y);
		}
		
		FOR(i,N) P[i]=N+1-P[i];
	}
	
	multiset<int> NG;
	FOR(i,N) NG.insert(RR[i]);
	ll ret=0;
	FOR(i,N) {
		x=*NG.begin();
		if(x>N) {
			ret+=N-i;
		}
		else {
			ret+=x-i;
		}
		
		NG.erase(NG.find(RR[i]));
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}