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


int T,N,M;
ll A[101010];
vector<int> G[101010];
ll S[101010],ave[101010];
vector<ll> rem[101010];


template<class V,int NV> class SegTree_3_mi {
public:
	vector<V> val, ma;
	SegTree_3_mi(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 1<<20;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
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
template<class V,int NV> class SegTree_3_ma {
public:
	vector<V> val, ma;
	SegTree_3_ma(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return -1<<20;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3_ma<int,1<<20> stma;
SegTree_3_mi<int,1<<20> stmi;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			stma.update(A[i],1<<18,1);
			stmi.update(0,A[i]+1,1);
		}
		FOR(i,M) {
			cin>>x;
			G[i].resize(x);
			S[i]=0;
			FORR(a,G[i]) {
				cin>>a;
				S[i]+=a;
			}
			ave[i]=(S[i]+x-1)/x;
			stma.update(ave[i],1<<18,-1);
			stmi.update(0,ave[i]+1,-1);
		}
		string ret;
		FOR(i,M) {
			stma.update(ave[i],1<<18,1);
			stmi.update(0,ave[i]+1,1);
			
			if(stmi.getval(0,1<<18)<0) {
				FORR(a,G[i]) ret+="0";
			}
			else {
				int cur=(1<<18)-1;
				for(j=17;j>=0;j--) if(stma.getval(0,cur-(1<<j)+1)>N-M) cur-=1<<j;
				FORR(a,G[i]) {
					if(S[i]-a<=1LL*cur*(G[i].size()-1)) ret+="1";
					else ret+="0";
				}
			}
			stma.update(ave[i],1<<18,-1);
			stmi.update(0,ave[i]+1,-1);
		}
		
		cout<<ret<<endl;
		FOR(i,N) {
			stma.update(A[i],1<<18,-1);
			stmi.update(0,A[i]+1,-1);
		}
		FOR(i,M) {
			stma.update(ave[i],1<<18,1);
			stmi.update(0,ave[i]+1,+1);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}