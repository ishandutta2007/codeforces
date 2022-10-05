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

int T,N,K;
ll A[202020];
ll S[202020];

template<class V,int NV> class SegTree_min {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_min(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

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
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_min<ll,1<<20> stmi;
SegTree_Pair<ll,1<<20> stma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		S[0]=A[0]=A[N+1]=1LL<<55;
		
		FOR(i,N) {
			cin>>A[i+1];
			S[i+1]=S[i]+A[i+1];
		}
		S[N+1]=S[N]+A[N+1];
		FOR(i,N+2) {
			stmi.update(i,S[i]);
			stma.update(i,S[i]);
		}
		int L=K,R=K;
		ll cur=A[K];
		while(L>0) {
			int TR=R;
			for(i=18;i>=0;i--) {
				int tmp=TR+(1<<i);
				if(tmp>N+2) continue;
				ll a=stmi.getval(R+1,tmp+1);
				if(cur+a-S[R]>=0) {
					TR=tmp;
				}
			}
			if(TR>R) {
				auto p=stma.getval(R+1,TR+1);
				if(p.first-S[R]>=0) {
					cur+=p.first-S[R];
					R=p.second;
				}
			}
			if(cur+A[L-1]<0) break;
			cur+=A[L-1];
			L--;
		}
		if(L>0) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}