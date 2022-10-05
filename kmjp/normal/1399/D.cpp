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

int T,N;
string S;
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int num=1;
		for(i=1;i<N;i++) if(S[i]==S[i-1]) num++;
		set<int> C[2];
		
		
		ret[0]=0;
		C[(S[0]-'0')^1].insert(0);
		
		for(i=1;i<N;i++) {
			x=S[i]-'0';
			if(C[x].size()) {
				y=*C[x].begin();
			}
			else {
				y=C[0].size()+C[1].size();
			}
			C[x].erase(y);
			C[x^1].insert(y);
			
			ret[i]=y;
		}
		cout<<C[0].size()+C[1].size()<<endl;
		FOR(i,N) cout<<ret[i]+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}