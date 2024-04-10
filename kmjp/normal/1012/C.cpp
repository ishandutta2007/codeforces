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
int A[5050];

int from[3050][2][2];
int to[3050][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3010) FOR(x,2) FOR(y,2) from[i][x][y]=1<<30;
	from[0][0][0]=0;
	
	for(i=2;i<=N+1;i++) {
		cin>>A[i];
		FOR(j,3010) FOR(x,2) FOR(y,2) to[j][x][y]=1<<30;
		
		FOR(j,3010) FOR(x,2) FOR(y,2) if(from[j][x][y]<1<<30) {
			// nottake
			to[j][0][0]=min({to[j][0][0],from[j][0][0],from[j][1][0]});
			to[j][1][0]=min({to[j][1][0],from[j][0][1]+max(0,A[i]-(A[i-1]-1))});
			// take
			to[j+1][0][1]=min({to[j+1][0][1],from[j][0][0]+max(0,A[i-1]-(A[i]-1)),from[j][1][0]+max(0,min(A[i-1],A[i-2]-1)-(A[i]-1))});
		}
		
		swap(from,to);
	}
	
	for(i=1;i<=(N+1)/2;i++) cout<<min({from[i][0][0],from[i][0][1],from[i][1][0],from[i][1][1]})<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}