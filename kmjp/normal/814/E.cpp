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
int D[51];
ll from[51][51][51][51];
ll to[51][51][51][51];
ll mo=1000000007;

const int CN=101;
ll C[CN][CN];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	
	from[D[0]==3][D[0]==2][D[1]==3][D[1]==2]=1;
	int a2,a1,b2,b1;
	
	for(i=2;i<N;i++) {
		ZERO(to);
		FOR(a2,N) FOR(a1,N) FOR(b2,N) if(a1+a2+b2<=N) FOR(b1,N) if(from[a2][a1][b2][b1]) {
			ll tmp=from[a2][a1][b2][b1];
			int y2,y1;
			if(a2 || a1) {
				for(y2=0;y2<=b2&&y2<=D[i]-1;y2++) for(y1=0;y1<=b1&&y2+y1<=D[i]-1;y1++) {
					ll Y=C[b2][y2]*C[b1][y1]%mo;
					int left=D[i]-1-y2-y1;
					if(a2) (to[a2-1][a1+1][b2-y2+(left==2)][b1-y1+y2+(left==1)] += a2*Y%mo*tmp)%=mo;
					if(a1) (to[a2][a1-1][b2-y2+(left==2)][b1-y1+y2+(left==1)] += a1*Y%mo*tmp)%=mo;
				}
			}
			else {
				if(b2) (to[b2-1][b1+1][D[i]==3][D[i]==2] += b2*tmp)%=mo;
				if(b1) (to[b2][b1-1][D[i]==3][D[i]==2] += b1*tmp)%=mo;
			}
		}
		
		
		swap(from,to);
	}
	cout<<from[0][0][0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}