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


int N;
ll A[505050];
ll X;
ll S[505050];
int ML[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,(N+1)/2) cin>>A[i];
	cin>>X;
	FOR(i,N-(N+1)/2) A[(N+1)/2+i]=X;
	
	FOR(i,N) S[i+1]=S[i]+A[i];
	
	if(S[N]>0) {
		cout<<N<<endl;
		return;
	}
	if(X<0) {
		int len=(N+1)/2;
		for(i=0;i<(N+1)/2;i++) {
			if(S[i+len]-S[i]<=0) break;
			int mlen=min((ll)N-i,len+(S[i+len]-S[i]-1)/(-X));
			ML[i]=mlen;
			if(i) ML[i]=min(ML[i],ML[i-1]);
			if(i+ML[i]>=N) {
				cout<<ML[i]<<endl;
				return;
			}
			
			
		}
	}
	
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}