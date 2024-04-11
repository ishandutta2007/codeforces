#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[1010];
int cap[3][1001][1001];
int con[3][3];

int getcap(int type) {
	int y,x,i;
	priority_queue<pair<int,int> > Q;
	
	con[type][type]=1;
	FOR(y,H) FOR(x,W) {
		cap[type][y][x]=10101010;
		if(S[y][x]=='1'+type) {
			cap[type][y][x]=0;
			Q.push(make_pair(0,y*1000+x));
		}
	}
	
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		int cy=r.second/1000,cx=r.second%1000;
		if(cap[type][cy][cx]!=-r.first) continue;
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i],tx=cx+dd[i^1];
			if(tx<0 || tx>=W || ty<0 || ty>=H || S[ty][tx]=='#') continue;
			if(cap[type][ty][tx]>-r.first+(S[ty][tx]=='.')) {
				cap[type][ty][tx]=-r.first+(S[ty][tx]=='.');
				Q.push(make_pair(-cap[type][ty][tx],ty*1000+tx));
			}
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,3) FOR(x,3) con[y][x]=10101010;
	FOR(y,H) cin>>S[y];
	FOR(i,3) getcap(i);
	
	int mi=100010000;
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='.') mi=min(mi,cap[0][y][x]+cap[1][y][x]+cap[2][y][x]-2);
		if(isdigit(S[y][x])) mi=min(mi,cap[0][y][x]+cap[1][y][x]+cap[2][y][x]);
	}
	if(mi>10000000) return _P("-1\n");
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}