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

int N,M;
string A,B;
int from[5050][3][3];
int to[5050][3][3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>A>>B;
	
	FOR(y,M+1) FOR(i,2) FOR(j,2) from[y][i][j]=-1<<30;
	from[0][0][0]=0;
	
	int ma=0;
	FOR(x,N+1) {
		FOR(y,M+1) FOR(i,2) FOR(j,2) to[y][i][j]=-1<<30;
		FOR(y,M+1) FOR(i,2) FOR(j,2) {
			int v=from[y][i][j];
			ma=max(ma,v);
			if(i<=0) to[y][0][j]=max(to[y][0][j],v);
			if(j<=0) from[y+1][i][0]=max(from[y+1][i][0],v);
			to[y][1][j]=max(to[y][1][j],v-1);
			from[y+1][i][1]=max(from[y+1][i][1],v-1);
			if(i<=1&&j<=1&&x<N&&y<M&&A[x]==B[y]) to[y+1][1][1]=max(to[y+1][1][1],v+2);
		}
		swap(from,to);
	}
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}