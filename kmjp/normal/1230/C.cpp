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

int N,M;
int p6[8];
int mat[7][7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		mat[x][y]=mat[y][x]=1;
	}
	
	p6[0]=1;
	FOR(i,7) p6[i+1]=p6[i]*6;
	
	int cur;
	int ma=0;
	FOR(cur,p6[7]) {
		int A[7]={};
		FOR(i,7) A[i]=cur/p6[i]%6;
		set<int> S;
		FOR(y,6) FOR(x,y+1) S.insert(x*10+y);
		
		FOR(y,7) FOR(x,y) if(mat[x][y]) {
			int p=min(A[x],A[y])*10+max(A[x],A[y]);
			S.erase(p);
		}
		
		
		ma=max(ma,21-(int)S.size());
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}