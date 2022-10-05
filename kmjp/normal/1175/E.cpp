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

int N,M;

int R[505050][21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		R[x][0]=max(R[x][0],y);
	}
	for(i=0;i<=500000;i++) {
		R[i][0]=max({i,R[i-1][0],R[i][0]});
	}
	FOR(x,20) {
		for(i=0;i<=500000;i++) R[i][x+1]=R[R[i][x]][x];
	}
	
	while(M--) {
		cin>>x>>y;
		int num=0;
		for(i=19;i>=0;i--) {
			if(R[x][i]<y) {
				x=R[x][i];
				num+=1<<i;
			}
		}
		
		if(R[x][0]>=y) {
			cout<<(num+1)<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}