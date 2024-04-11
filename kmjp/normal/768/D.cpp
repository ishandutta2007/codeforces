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

int K,Q;
int P[10101];
double PP[8000][1050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>Q;
	
	PP[0][0]=1;
	FOR(i,7300) {
		FOR(j,K+1) {
			PP[i+1][j]   += PP[i][j]*j/K;
			PP[i+1][j+1] += PP[i][j]*(K-j)/K;
		}
	}
	
	FOR(i,Q) {
		cin>>x;
		for(j=0;j<=7300;j++) {
			if(PP[j][K]>=x/2000.0-1e-9) {
				cout<<j<<endl;
				break;
			}
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}