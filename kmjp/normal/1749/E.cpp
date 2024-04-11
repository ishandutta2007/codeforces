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

int T,H,W;
string S[202020];
vector<int> D[202020];
vector<pair<int,int>> F[202020];

int ok(int y,int x) {
	if(y<0||y>=H||x<0||x>=W) return 0;
	if(y&&S[y-1][x]=='#') return 0;
	if(y+1<H&&S[y+1][x]=='#') return 0;
	if(x&&S[y][x-1]=='#') return 0;
	if(x+1<W&&S[y][x+1]=='#') return 0;
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		deque<pair<int,int>> Q;
		FOR(y,H) {
			cin>>S[y];
			D[y].resize(W);
			F[y].resize(W);
			FOR(x,W) D[y][x]=1<<30;
		}
		FOR(y,H) {
			if(S[y][0]=='#') {
				D[y][0]=0;
				Q.push_front({y,0});
			}
			else if(ok(y,0)) {
				D[y][0]=1;
				Q.push_back({y,0});
			}
		}
		int gy=-1,gx=-1;
		
		while(Q.size()) {
			int cy=Q.front().first;
			int cx=Q.front().second;
			Q.pop_front();
			if(cx==W-1) {
				gy=cy;
				gx=cx;
				break;
			}
			int dy[4]={1,1,-1,-1};
			int dx[4]={1,-1,1,-1};
			FOR(i,4) {
				int ty=cy+dy[i];
				int tx=cx+dx[i];
				if(ok(ty,tx)==0) continue;
				if(S[ty][tx]=='#' && D[ty][tx]>D[cy][cx]){
					F[ty][tx]={cy,cx};
					D[ty][tx]=D[cy][cx];
					Q.push_front({ty,tx});
				}
				if(S[ty][tx]=='.' && D[ty][tx]>D[cy][cx]+1){
					F[ty][tx]={cy,cx};
					D[ty][tx]=D[cy][cx]+1;
					Q.push_back({ty,tx});
				}
			}
		}
		if(gy==-1) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			while(1) {
				auto p=F[gy][gx];
				S[gy][gx]='#';
				if(gx==0) break;
				gy=p.first;
				gx=p.second;
			}
			FOR(y,H) cout<<S[y]<<endl;
		}
				
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}