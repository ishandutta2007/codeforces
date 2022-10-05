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
int N,K;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>S;
		int C[2]={};
		FOR(i,N) C[S[i]-'0']++;
		
		int mi=1<<30;
		FOR(i,K) {
			int D[2]={};
			int F[3]={0,0,0};
			
			for(j=i;j<N;j+=K) {
				int T[3]={1<<30,1<<30,1<<30};
				D[S[j]-'0']++;
				
				if(S[j]=='0') {
					T[0]=F[0];
					T[1]=min(F[0],F[1])+1;
					T[2]=min({F[0],F[1],F[2]});
				}
				else {
					T[0]=F[0]+1;
					T[1]=min(F[0],F[1]);
					T[2]=min({F[0],F[1],F[2]})+1;
				}
				swap(F,T);
				F[1]=min(F[0],F[1]);
				F[2]=min(F[2],F[1]);
			}
			
			int sum=C[1]-D[1]+F[2];
			mi=min(mi,sum);
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}