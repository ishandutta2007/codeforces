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

int T;
int N;
int A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> P[2];
		FOR(i,N) {
			cin>>x;
			P[x%2].push_back(x);
		}
		if(N%2) {
			cout<<"NO"<<endl;
		}
		else if(P[0].size()%2==0 && P[1].size()%2==0) {
			cout<<"YES"<<endl;
		}
		else {
			int ok=0;
			FORR(a,P[0]) FORR(b,P[1]) if(abs(a-b)==1) ok=1;
			if(ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}