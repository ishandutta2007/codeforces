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

int N,Q;
int A[101010];
pair<int,int> P[101010];
int L[101],R[101];
ll ret[101];
set<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	
	FOR(i,N-1) P[i]={abs(A[i+1]-A[i]),i};
	sort(P,P+(N-1));
	reverse(P,P+(N-1));
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--,R[i]--;
	}
	S.insert(-1);
	S.insert(N-1);
	
	FOR(i,N-1) {
		x=P[i].second;
		auto it=S.lower_bound(x);
		int RR=*it;
		it--;
		int LL=1+(*it);
		
		FOR(j,Q) {
			ll NR=min(RR,R[j]);
			ll NL=max(LL,L[j]);
			
			if(NL<=x && x+1<=NR) {
				ll num=(x-NL+1)*(NR-x);
				ret[j]+=num*P[i].first;
			}
		}
		S.insert(x);
	}
	FOR(j,Q) cout<<ret[j]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}