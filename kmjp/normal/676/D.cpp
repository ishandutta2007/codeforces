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

int H,W;
int sy,sx,gy,gx;
string S;
int mask[1010][1010];
int dist[1010][1010][4];

int rot(int mask,int num) {
	while(num--) mask=((mask<<1)&0xe) | ((mask>>3)&1);
	return mask;
}

int cango(int m1,int m2,int dir) {
	int c=0;
	if(((m1 & (1<<dir))==0)) return 0;
	dir=(dir+2)%4;
	if(((m2 & (1<<dir))==0)) return 0;
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S;
		FOR(x,W) {
			if(S[x]=='+' || S[x]=='|' || S[x]=='^' || S[x]=='L'|| S[x]=='R'|| S[x]=='D') mask[y][x] |= 1; // up;
			if(S[x]=='+' || S[x]=='|' || S[x]=='v' || S[x]=='L'|| S[x]=='R'|| S[x]=='U') mask[y][x] |= 4; // down;
			if(S[x]=='+' || S[x]=='-' || S[x]=='<' || S[x]=='R'|| S[x]=='U'|| S[x]=='D') mask[y][x] |= 8; // left;
			if(S[x]=='+' || S[x]=='-' || S[x]=='>' || S[x]=='L'|| S[x]=='U'|| S[x]=='D') mask[y][x] |= 2; // right;
		}
	}
	cin>>sy>>sx;
	sy--,sx--;
	cin>>gy>>gx;
	gy--,gx--;
	
	memset(dist,0x3f,sizeof(dist));
	dist[sy][sx][0]=0;
	queue<int> Q;
	Q.push(sy*1000+sx);
	while(Q.size()) {
		auto r=Q.front();
		int cy=r/1000%1000;
		int cx=r%1000;
		int cr=r/1000000;
		Q.pop();
		int cost = dist[cy][cx][cr];
		if(dist[cy][cx][(cr+1)%4]>cost+1) {
			dist[cy][cx][(cr+1)%4]=cost+1;
			Q.push(((cr+1)%4)*1000000+cy*1000+cx);
		}
		
		FOR(i,4) {
			int dx[4]={0,1,0,-1};
			int dy[4]={-1,0,1,0};
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
			
			if(cango(rot(mask[cy][cx],cr),rot(mask[ty][tx],cr),i)) {
				if(dist[ty][tx][cr]>cost+1) {
					dist[ty][tx][cr] = cost+1;
					Q.push(cr*1000000+ty*1000+tx);
				}
			}
		}
		
	}
	int mi=5010100;
	FOR(i,4) mi=min(mi,dist[gy][gx][i]);
	if(mi>5010000) mi=-1;
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}