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

int N,Q;
int A[303030];

int R[303030][20];
int la[20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,20) R[N][i]=la[i]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,20) R[i][j]=N;
		FOR(j,20) if(A[i]&(1<<j)) {
			
			if(la[j]!=N) {
				R[i][j]=min(R[i][j],la[j]);
				FOR(x,20) R[i][x]=min(R[i][x],R[la[j]][x]);
			}
			
			la[j]=i;
		}
	}
	
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		FOR(i,20) if((A[y]&(1<<i)) && R[x][i]<=y) break;
		if(i==20) {
			cout<<"Fou"<<endl;
		}
		else {
			cout<<"Shi"<<endl;
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}