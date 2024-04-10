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
int N,M;
string S[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(y,N) cin>>S[y];
		
		string T;
		FOR(i,M) {
			FOR(j,26) {
				T=S[0];
				T[i]='a'+j;
				int ok=1;
				FOR(x,N) {
					int num=0;
					FOR(y,M) if(S[x][y]!=T[y]) num++;
					if(num>1) ok=0;
				}
				if(ok) {
					cout<<T<<endl;
					goto out;
				}
			}
		}
		cout<<-1<<endl;
		out:
		;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}