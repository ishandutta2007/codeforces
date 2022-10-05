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
string S;

int from[2][2],to[2][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		int ret=1<<30;
		FOR(x,2) FOR(y,2) {
			from[0][0]=from[0][1]=from[1][0]=from[1][1]=1<<30;
			from[x][y]=0;
			if(S[0]=='R' && x==0) from[x][y]++;
			if(S[0]=='L' && x==1) from[x][y]++;
			if(S[1]=='R' && y==0) from[x][y]++;
			if(S[1]=='L' && y==1) from[x][y]++;
			for(k=2;k<N;k++) {
				to[0][0]=to[0][1]=to[1][0]=to[1][1]=1<<30;
				
				FOR(i,2) FOR(j,2) FOR(r,2) {
					int cost=0;
					if(S[k]=='R'&&r==0) cost++;
					if(S[k]=='L'&&r==1) cost++;
					if(i==j&&j==r) continue;
					to[j][r]=min(to[j][r],from[i][j]+cost);
				}
				
				swap(from,to);
			}
			FOR(i,2) FOR(j,2) {
				if(i==1&&x==1&&j==1) continue;
				if(i==0&&x==0&&j==0) continue;
				if(j==1&&x==1&&y==1) continue;
				if(j==0&&x==0&&y==0) continue;
				ret=min(ret,from[i][j]);
			}
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