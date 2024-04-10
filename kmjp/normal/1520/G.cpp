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

int H,W,C;
int A[2020][2020];
ll D[2020][2020][2];
ll mi[2]={1LL<<60,1LL<<60};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> cand;
	cin>>H>>W>>C;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		D[y][x][0]=D[y][x][1]=1LL<<60;
		if(D[y][x]>0) cand.push_back(y*W+x);
	}
	queue<int> Q;
	D[0][0][0]=D[H-1][W-1][1]=0;
	Q.push(0);
	Q.push(H*W+(H-1)*W+(W-1));
	while(Q.size()) {
		int id=Q.front()/(H*W);
		int cy=Q.front()%(H*W)/W;
		int cx=Q.front()%W;
		Q.pop();
		if(A[cy][cx]>0) mi[id]=min(mi[id],D[cy][cx][id]+A[cy][cx]);
		FOR(i,4) {
			int dd[]={0,1,0,-1};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||A[ty][tx]==-1) continue;
			if(D[ty][tx][id]>D[cy][cx][id]+C) {
				D[ty][tx][id]=D[cy][cx][id]+C;
				Q.push(id*H*W+ty*W+tx);
			}
		}
	}
	ll ret=min(mi[0]+mi[1],D[H-1][W-1][0]);
	if(ret>=1LL<<60) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}