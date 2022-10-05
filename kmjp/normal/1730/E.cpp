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

int T,N;
int LG[505050],RG[505050];
int LL[505050],RL[505050];
vector<int> di[1010101];
vector<int> D[1010101];
int pre[1010101];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(val[entry],v); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> stma,stmi;
int A[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) {
		for(j=2*i;j<=1000000;j+=i) di[j].push_back(i);
	}
	
	cin>>T;
	while(T--) {
		
		FOR(i,1000100) D[i].clear(), pre[i]=-10000;
		
		cin>>N;
		FORR(v,stma.val) v=0;
		FORR(v,stmi.val) v=-(N+1);
		FOR(i,N) {
			cin>>A[i+1];
			D[A[i+1]].push_back(i+1);
			LG[i+1]=stma.getval(A[i+1],1<<20);
			LL[i+1]=stma.getval(0,A[i+1]);
			stma.update(A[i+1],i+1);
		}
		for(i=N;i>=1;i--) {
			RG[i]=-stmi.getval(A[i]+1,1<<20);
			RL[i]=-stmi.getval(0,A[i]);
			stmi.update(A[i],-i);
		}
		for(i=1;i<=1000000;i++) reverse(ALL(D[i]));
		
		ll ret=0;
		for(i=1;i<=N;i++) {
			int TL=LG[i],TR=RG[i];
			
			int AL=max(TL,LL[i]);
			int AR=min(TR,RL[i]);
			ret+=1LL*(i-AL)*(AR-i);
			
			FORR(d,di[A[i]]) {
				while(D[d].size()&&D[d].back()<i) {
					pre[d]=D[d].back();
					D[d].pop_back();
				}
				
				int SL=TL,SR=TR;
				if(pre[d]>TL&&RL[pre[d]]>i) SL=pre[d];
				if(D[d].size()&&LL[D[d].back()]<i) SR=D[d].back();
				
				//cout<<"#"<<d<<" "<<SL<<" "<<SR<<" "<<ret<<endl;
				if(SL>TL&&SR<TR) {
					int CL=max(TL,LL[SL]);
					int CR=min(TR,RL[SR]);
					ret+=1LL*(SL-CL)*(SR-i);
					ret+=1LL*(i-SL)*(CR-SR);
					ret+=1LL*(SL-CL)*(CR-SR);
				}
				else if(SL>TL) {
					int CL=max(TL,LL[SL]);
					int CR=min(TR,RL[SL]);
					ret+=1LL*(SL-CL)*(CR-i);
				}
				else if(SR<TR) {
					int CL=max(TL,LL[SR]);
					int CR=min(TR,RL[SR]);
					ret+=1LL*(i-CL)*(CR-SR);
				}
			}
			//cout<<i<<" "<<A[i]<<" "<<LG[i]<<" "<<LL[i]<<" "<<RG[i]<<" "<<RL[i]<<" "<<ret<<endl;
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}