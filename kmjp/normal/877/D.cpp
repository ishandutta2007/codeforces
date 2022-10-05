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
string S[1010];
int SY,SX,GY,GX;
int D[1010][1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(y,H) cin>>S[y];
	cin>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	
	FOR(y,H) FOR(x,W) D[y][x]=1<<20;
	int step=0;
	D[SY][SX]=0;
	queue<int> Q;
	Q.push(SY*1000+SX);
	
	while(Q.size()) {
		queue<int> NQ;
		
		while(Q.size()) {
			int cy=Q.front()/1000;
			int cx=Q.front()%1000;
			Q.pop();
			
			// up;
			for(i=1;i<=K;i++) {
				int ty=cy-i;
				int tx=cx;
				if(ty<0 || S[ty][tx]=='#' || D[ty][tx]<=D[cy][cx]) break;
				if(D[ty][tx]>step+1) D[ty][tx]=step+1, NQ.push(ty*1000+tx);
			}
			// down
			for(i=1;i<=K;i++) {
				int ty=cy+i;
				int tx=cx;
				if(ty>=H || S[ty][tx]=='#' || D[ty][tx]<=D[cy][cx]) break;
				if(D[ty][tx]>step+1) D[ty][tx]=step+1, NQ.push(ty*1000+tx);
			}
			// left;
			for(i=1;i<=K;i++) {
				int ty=cy;
				int tx=cx-i;
				if(tx<0 || S[ty][tx]=='#' || D[ty][tx]<=D[cy][cx]) break;
				if(D[ty][tx]>step+1) D[ty][tx]=step+1, NQ.push(ty*1000+tx);
			}
			// right
			for(i=1;i<=K;i++) {
				int ty=cy;
				int tx=cx+i;
				if(tx>=W || S[ty][tx]=='#' || D[ty][tx]<=D[cy][cx]) break;
				if(D[ty][tx]>step+1) D[ty][tx]=step+1, NQ.push(ty*1000+tx);
			}
		} 
		swap(Q,NQ);
		step++;
	}
	
	
	if(D[GY][GX]>=1<<20) cout<<-1<<endl;
	else cout<<D[GY][GX]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}