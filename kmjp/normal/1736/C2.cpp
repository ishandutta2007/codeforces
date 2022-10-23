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

int T,N,A[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
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
SegTree_1<int,1<<20> st;

vector<pair<int,ll>> add[202020];
int TR[202020],TL[202020];
ll SR[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		st.update(i,A[i]-i);
	}
	ll ret=0;
	deque<pair<int,int>> D;
	FOR(i,N) {
		int R=i+1;
		for(j=20;j>=0;j--) if(R+(1<<j)<=N&&st.getval(i,R+(1<<j))+i>=1) R+=(1<<j);
		ret+=R-i;
		if(R!=N) {
			int NR=R+1;
			for(j=20;j>=0;j--) if(NR+(1<<j)<=N&&st.getval(NR,NR+(1<<j))+i>=1) NR+=(1<<j);
			add[R].push_back({(R-i+1)-A[R],NR-R});
		}
		TR[i]=R;
		SR[i+1]=SR[i]+R;
		D.push_back({TR[i]-1,i});
		while(D.size()&&D[0].first<i) D.pop_front();
		TL[i]=D[0].second;
	}
	FOR(i,N) {
		sort(ALL(add[i]));
		for(j=1;j<add[i].size();j++) add[i][j].second+=add[i][j-1].second;
	}
	int Q;
	cin>>Q;
	while(Q--) {
		int P,X;
		cin>>P>>X;
		P--;
		if(A[P]==X) {
			cout<<ret<<endl;
		}
		else if(X<A[P]) {
			int CR=P-X;
			if(CR<TL[P]) {
				cout<<ret<<endl;
			}
			else {
				ll dif=SR[CR+1]-SR[TL[P]];
				dif-=1LL*P*(CR+1-TL[P]);
				cout<<ret-dif<<endl;
			}
			
		}
		else {
			pair<int,ll> p={X-A[P]+1,0};
			x=lower_bound(ALL(add[P]),p)-add[P].begin();
			ll ret2=ret;
			if(x) ret2+=add[P][x-1].second;
			cout<<ret2<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}