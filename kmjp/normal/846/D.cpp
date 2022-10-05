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

int H,W,K,Q;
vector<vector<int>> V;
int mat[505][505];

int broken(int t) {
	if(t+1<K*K) return 0;
	
	ZERO(mat);
	int i;
	FOR(i,t+1) mat[V[i][1]][V[i][2]]=1;
	int y,x;
	FOR(y,H) {
		for(x=W-1;x>=0;x--) if(mat[y][x]) mat[y][x]+=mat[y][x+1];
		FOR(x,W) mat[y][x]=mat[y][x]>=K;
	}
	FOR(x,W) {
		for(y=H-1;y>=0;y--) if(mat[y][x]) {
			mat[y][x]+=mat[y+1][x];
			if(mat[y][x]>=K) return 1;
		}
	}
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>Q;
	FOR(i,Q) {
		cin>>y>>x>>r;
		V.push_back({r,y-1,x-1});
	}
	sort(ALL(V));
	
	int tim=Q-1;
	if(broken(tim)==0) return _P("-1\n");
	for(i=20;i>=0;i--) if(broken(tim-(1<<i))) tim-=1<<i;
	cout<<V[tim][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}