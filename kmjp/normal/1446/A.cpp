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
int N;
ll V;
ll W[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>V;
		vector<ll> A[2];
		ll S=0;
		FOR(i,N) {
			cin>>W[i];
			if(W[i]<(V+1)/2&&S<(V+1)/2) {
				A[0].push_back(i);
				S+=W[i];
			}
			else if(W[i]>=(V+1)/2&&W[i]<=V) {
				A[1].push_back(i);
			}
		}
		
		if(A[1].size()) {
			cout<<1<<endl;
			cout<<A[1][0]+1<<endl;
		}
		else if(S>=(V+1)/2) {
			cout<<A[0].size()<<endl;
			FORR(v,A[0]) cout<<v+1<<" ";
			cout<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}