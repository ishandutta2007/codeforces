#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N,K;
int A[202020],B[202020],P[202020],Q[202020];
int NG[202020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			P[A[i]]=i;
			NG[i]=0;
		}
		set<int> ok;
		FOR(i,N) ok.insert(i);
		FOR(i,K) {
			cin>>B[i];
			B[i]--;
			Q[i]=P[B[i]];
			NG[Q[i]]=1;
		}
		ll ret=1;
		FOR(i,K) {
			x=Q[i];
			ok.erase(x);
			auto it=ok.lower_bound(x);
			int num=0;
			if(it!=ok.end()&&NG[*it]==0) num++;
			if(it!=ok.begin()&&NG[*prev(it)]==0) num++;
			ret=ret*num%mo;
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