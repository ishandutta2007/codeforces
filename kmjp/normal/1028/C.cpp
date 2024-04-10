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
int L[2][200000],R[2][200000],U[2][200000],D[2][200000];
int X1[200000],X2[200000],Y1[200000],Y2[200000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	L[0][0]=U[0][0]=L[1][N+1]=U[1][N+1]=-1000000001;
	R[0][0]=D[0][0]=R[1][N+1]=D[1][N+1]=1000000001;
	for(i=1;i<=N;i++) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		L[0][i]=max(L[0][i-1],X1[i]);
		R[0][i]=min(R[0][i-1],X2[i]);
		U[0][i]=max(U[0][i-1],Y1[i]);
		D[0][i]=min(D[0][i-1],Y2[i]);
	}
	for(i=N;i>=1;i--) {
		L[1][i]=max(L[1][i+1],X1[i]);
		R[1][i]=min(R[1][i+1],X2[i]);
		U[1][i]=max(U[1][i+1],Y1[i]);
		D[1][i]=min(D[1][i+1],Y2[i]);
		int AL=max(L[0][i-1],L[1][i+1]);
		int AR=min(R[0][i-1],R[1][i+1]);
		int AU=max(U[0][i-1],U[1][i+1]);
		int AD=min(D[0][i-1],D[1][i+1]);
		if(AL<=AR && AU<=AD) {
			cout<<AL<<" "<<AU<<endl;
			return;
		}
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}