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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

int N;
pair<int,int> P[202020];
int F[202020];
ll mo=1000000007;

ll sp[202020];
ll dp[202020];

map<ll,ll> M;
vector<pair<ll,ll>> add[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		P[i].first=-P[i].first;
	}
	P[N].first=-1LL<<30;
	P[N].second=(1LL<<30)-1;
	P[N+1].first=0;
	P[N+1].second=0;
	N+=2;
	sort(P,P+N+2);
	
	FOR(i,N) {
		sp[i]=1<<30;
		F[i]=P[i].first;
		st.update(i,P[i].second);
	}
	sp[0]=0;
	dp[0]=1;
	FOR(i,N) {
		
		FORR(e,add[i]) {
			(M[e.first]+=e.second)%=mo;
			if(M[e.first]==0) M.erase(e.first);
		}
		
		
		if(i) {
			if(M.begin()->first==0) {
				sp[i]=P[i].second;
			}
			else {
				sp[i]=M.begin()->first+P[i].first+P[i].second;
			}
			dp[i]=M.begin()->second;
		}
		
		//cout<<i<<" "<<-P[i].first<<" "<<P[i].second<<" "<<sp[i]<<" "<<dp[i]<<endl;
		if(i==N-1) break;
		int L=lower_bound(F+i+1,F+N,-P[i].second)-F;
		x=st.getval(L,N);
		int R=lower_bound(F+i+1,F+N,-x)-F;

		/*
		cout<<i<<" "<<-P[i].first<<" "<<P[i].second<<" "<<L<<" "<<R<<" "<<sp[i]<<" "<<dp[i]<<endl;
		FORR(m,M) cout<<m.first<<":"<<m.second<<"  ";
		cout<<endl;
		*/
		
		
		add[L].push_back({sp[i],dp[i]});
		if(L<N-1) add[R].push_back({sp[i],mo-dp[i]});
	}
	
	cout<<M.begin()->second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}