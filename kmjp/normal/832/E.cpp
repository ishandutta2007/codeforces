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

int N,M,Q;
string S[505],T;
int mo=5;
int mat[500][800];

int rev(int a) {
	int revt[]={0,1,3,2,4};
	return revt[a];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,M) mat[x][y]=S[y][x]-'a';
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>T;
		FOR(x,M) mat[x][N+i]=T[x]-'a';
	}
	
	ll pat=1;
	int step=0,ret=0;
	FOR(step,N) {
		for(y=ret;y<M;y++) if(mat[y][step]) break;
		if(y==M) {
			pat=pat*5%1000000007;
			continue;
		}
		for(x=step;x<N+Q;x++) swap(mat[ret][x],mat[y][x]);
		int re=rev(mat[ret][step]);
		for(x=step;x<N+Q;x++) mat[ret][x]=mat[ret][x]*re%mo;
		
		FOR(y,M) if(y!=ret && mat[y][step]) {
			re=mat[y][step];
			for(x=step;x<N+Q;x++) mat[y][x]=((mat[y][x]-re*mat[ret][x])%mo+mo)%mo;
		}
		ret++;
	}
	
	
	FOR(i,Q) {
		for(x=ret;x<M;x++) if(mat[x][N+i]) break;
		if(x==M) cout<<pat<<endl;
		else cout<<0<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}