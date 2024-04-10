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

int Q;
int N;
int A[303030];
int R[303030];
map<int,int> M[303030];
ll dp[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>Q;
	while(Q--) {
		cin>>N;
		
		FOR(i,N) {
			cin>>A[i];
			M[i].clear();
		}
		M[N].clear();
		dp[N]=0;
		
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			if(M[i+1].count(A[i])) {
				R[i]=M[i+1][A[i]];
				swap(M[i],M[R[i]+1]);
				dp[i]=1+dp[R[i]+1];
			}
			else {
				dp[i]=0;
				R[i]=N;
			}
			M[i][A[i]]=i;
			ret+=dp[i];
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