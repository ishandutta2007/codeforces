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

int H,W;
int A[1010][1010];
int did[1010][1010];

vector<vector<int>> R;
set<int> S;
queue<pair<int,int>> Q;

int check(int y,int x) {
	if(y<0||x<0||y+1>=H||x+1>=W) return 0;
	if(did[y][x]) return 0;
	set<int> S;
	S.insert(A[y][x]);
	S.insert(A[y][x+1]);
	S.insert(A[y+1][x]);
	S.insert(A[y+1][x+1]);
	S.erase(0);
	if(S.size()<=1) {
		if(S.size()) R.push_back({y+1,x+1,*S.begin()});
		A[y][x]=0;
		A[y][x+1]=0;
		A[y+1][x]=0;
		A[y+1][x+1]=0;
		did[y][x]=1;
		Q.push({y,x});
		return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	FOR(y,H-1) FOR(x,W-1) check(y,x);
	while(Q.size()) {
		y=Q.front().first;
		x=Q.front().second;
		Q.pop();
		for(int ty=y-1;ty<=y+1;ty++) for(int tx=x-1;tx<=x+1;tx++) check(ty,tx);
	}
	FOR(y,H) FOR(x,W) if(A[y][x]) {
		cout<<-1<<endl;
		return;
	}
	reverse(ALL(R));
	_P("%d\n",(int)R.size());
	FORR(r,R) {
		_P("%d %d %d\n",r[0],r[1],r[2]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}