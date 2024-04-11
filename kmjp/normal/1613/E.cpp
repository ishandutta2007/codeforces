#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int H,W;
string S[1010101];
char buf[1010101];
int in[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&H,&W);
		FOR(y,H) {
			scanf("%s",buf);
			S[y]=buf;
		}
		FOR(y,H) FOR(x,W) in[y*W+x]=0;
		
		int SY,SX;
		queue<int> Q;
		FOR(y,H) FOR(x,W) if(S[y][x]=='L') {
			if(y) Q.push((y-1)*W+x), in[(y-1)*W+x]++;
			if(y+1<H) Q.push((y+1)*W+x), in[(y+1)*W+x]++;
			if(x) Q.push(y*W+x-1), in[y*W+x-1]++;
			if(x+1<W) Q.push(y*W+x+1), in[y*W+x+1]++;
		}
		
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			in[Q.front()]=0;
			Q.pop();
			if(S[cy][cx]!='.') continue;
			int fr=0;
			int d[]={1,0,-1,0};
			FOR(i,4) {
				int dy=cy+d[i];
				int dx=cx+d[i^1];
				if(dy<0||dy>=H||dx<0||dx>=W) continue;
				if(S[dy][dx]=='.') fr++;
			}
			if(fr<=1) {
				S[cy][cx]='+';
				FOR(i,4) {
					int dy=cy+d[i];
					int dx=cx+d[i^1];
					if(dy<0||dy>=H||dx<0||dx>=W) continue;
					if(S[dy][dx]=='.'&&in[dy*W+dx]==0) {
						Q.push(dy*W+dx);
						in[dy*W+dx]=1;
					}
				}
				
			}
		}
		FOR(y,H) _P("%s\n",S[y].c_str());
		
		
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}