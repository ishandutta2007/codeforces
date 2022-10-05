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


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

int N;
ll T,A[202020],S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	vector<ll> V;
	V.push_back(-1LL<<60);
	V.push_back(0);
	V.push_back(T-1);
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		V.push_back(S[i+1]);
		V.push_back(S[i+1]+T-1);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N+1) {
		S[i]=lower_bound(ALL(V),S[i])-V.begin();
		bt.add(S[i],1);
	}
	
	ll ret=0;
	FOR(i,N) {
		bt.add(S[i],-1);
		ll v=V[S[i]]+T-1;
		ret+=bt(lower_bound(ALL(V),v)-V.begin());
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}