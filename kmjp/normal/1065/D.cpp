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
int A[10][10];
int PX[100],PY[100];

pair<int,int> D[10][10][100][3];
vector<pair<int,int>> V[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	V[0]={{2,1},{1,2},{2,-1},{1,-2},{-2,1},{-1,2},{-2,-1},{-1,-2}};
	for(i=1;i<=9;i++) {
		V[1].push_back({i,0});
		V[1].push_back({0,i});
		V[1].push_back({-i,0});
		V[1].push_back({0,-i});
		V[2].push_back({i,i});
		V[2].push_back({i,-i});
		V[2].push_back({-i,i});
		V[2].push_back({-i,-i});
	}
	
	
	cin>>N;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		PX[A[y][x]-1]=x;
		PY[A[y][x]-1]=y;
		FOR(i,N*N) FOR(j,3) D[y][x][i][j]={1<<20,0};
	}
	queue<vector<int>> Q;
	FOR(i,3) {
		D[PY[0]][PX[0]][0][i]={0,0};
		Q.push({PY[0],PX[0],0,i});
	}
	
	pair<int,int> ret={101010,101010};
	while(Q.size()) {
		int cy=Q.front()[0];
		int cx=Q.front()[1];
		int step=Q.front()[2];
		int type=Q.front()[3];
		Q.pop();
		
		pair<int,int> nex=D[cy][cx][step][type];
		if(step==N*N-1) {
			ret=min(ret,nex);
			continue;
		}
		nex.first++;
		nex.second++;
		FOR(i,3) {
			if(D[cy][cx][step][i]>nex) {
				D[cy][cx][step][i]=nex;
				Q.push({cy,cx,step,i});
			}
		}
		nex.second--;
		FORR(d,V[type]) {
			int ty=cy+d.first;
			int tx=cx+d.second;
			if(ty<0 || ty>=N || tx<0 || tx>=N) continue;
			int ns=step+(ty==PY[step+1]&&tx==PX[step+1]);
			if(D[ty][tx][ns][type]>nex) {
				D[ty][tx][ns][type]=nex;
				Q.push({ty,tx,ns,type});
			}
		}
	}
	cout<<ret.first<<" "<<ret.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}