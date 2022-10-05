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

int H,W,K;
int Q,R1,C1,R2,C2;

int A[1010][1010];
int D[1010][1010][41];
int E[41][41];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&H,&W,&K);
	FOR(y,H) FOR(x,W) {
		scanf("%d",&i);
		A[y][x]=i-1;
	}
	FOR(y,K) FOR(x,K) E[y][x]=(y==x)?0:202020;
	
	FOR(i,K) {
		queue<int> Q;
		FOR(y,H) FOR(x,W) {
			if(A[y][x]==i) {
				D[y][x][i]=0;
				Q.push(y*1000+x);
			}
			else {
				D[y][x][i]=202020;
			}
		}
		while(Q.size()) {
			y=Q.front()/1000;
			x=Q.front()%1000;
			Q.pop();
			E[A[y][x]][i]=min(E[A[y][x]][i],D[y][x][i]);
			
			FOR(j,4) {
				int dd[4]={1,0,-1,0};
				int ty=y+dd[j];
				int tx=x+dd[j^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(D[ty][tx][i]>D[y][x][i]+1) {
					D[ty][tx][i]=D[y][x][i]+1;
					Q.push(ty*1000+tx);
				}
			}
		}
	}
	FOR(r,K) FOR(x,K) FOR(y,K) E[x][y]=min(E[x][y],E[x][r]+1+E[r][y]);
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d%d",&R1,&C1,&R2,&C2);
		R1--,C1--,R2--,C2--;
		int ret=abs(R2-R1)+abs(C2-C1);
		
		FOR(x,K) {
			ret=min(ret,D[R1][C1][x]+D[R2][C2][x]+1);
			FOR(y,K) ret=min(ret,D[R1][C1][x]+D[R2][C2][y]+E[x][y]+2);
		}
		_P("%d\n",ret);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}