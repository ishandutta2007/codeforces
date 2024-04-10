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
int H,W;
string S[505050];
int R[50505];
int C[50505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>H>>W;
		FOR(x,W) C[x]=0;
		FOR(y,H) {
			cin>>S[y];
			R[y]=0;
			FOR(x,W) if(S[y][x]=='*') R[y]++,C[x]++;
		}
		int mi=101010;
		FOR(y,H) FOR(x,W) {
			if(S[y][x]=='*') mi=min(mi,H+W-R[y]-C[x]);
			else mi=min(mi,H+W-R[y]-C[x]-1);
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