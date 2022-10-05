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
ll X[101010],Y[101010];

ll SY[101010][4];
ll SX[101010][4];
int from[101010][4];
int S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		FOR(j,4) from[i+1][j]=-1;
		SY[i+1][0]=SY[i+1][1]=1LL<<30;
		SY[i+1][2]=SY[i+1][3]=-1LL<<30;
		SX[i+1][0]=SX[i+1][3]=1LL<<30;
		SX[i+1][1]=SX[i+1][2]=-1LL<<30;
		FOR(j,8) if(from[i][j/2]>=0) {
			ll nx=SX[i][j/2]+((j%2)?X[i]:-X[i]);
			ll ny=SY[i][j/2]+((j%2)?Y[i]:-Y[i]);
			
			// 0
			if(nx>=0 && ny>=0 && nx*nx+ny*ny<=SY[i+1][0]*SY[i+1][0]+SX[i+1][0]*SX[i+1][0]) from[i+1][0]=j, SY[i+1][0]=ny, SX[i+1][0]=nx;
			if(nx<=0 && ny>=0 && nx*nx+ny*ny<=SY[i+1][1]*SY[i+1][1]+SX[i+1][1]*SX[i+1][1]) from[i+1][1]=j, SY[i+1][1]=ny, SX[i+1][1]=nx;
			if(nx<=0 && ny<=0 && nx*nx+ny*ny<=SY[i+1][2]*SY[i+1][2]+SX[i+1][2]*SX[i+1][2]) from[i+1][2]=j, SY[i+1][2]=ny, SX[i+1][2]=nx;
			if(nx>=0 && ny<=0 && nx*nx+ny*ny<=SY[i+1][3]*SY[i+1][3]+SX[i+1][3]*SX[i+1][3]) from[i+1][3]=j, SY[i+1][3]=ny, SX[i+1][3]=nx;
			
		}
	}
	
	FOR(i,4) if(from[N][i]>=0 && SY[N][i]*SY[N][i]+SX[N][i]*SX[N][i]<=1500000LL*1500000LL) {
		int cur=N;
		int pos=i;
		while(cur>0) {
			if(from[cur][pos]%2==0) S[cur-1]=1;
			else S[cur-1]=-1;
			pos=from[cur][pos]/2;
			cur--;
		}
		break;
	}
	FOR(i,N) cout<<S[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}