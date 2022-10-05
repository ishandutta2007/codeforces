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


string S,T;
int A,B;

int hoge[202][202][204];
vector<int> from[202][202][204];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	
	memset(hoge,0x11,sizeof(hoge));
	hoge[0][0][0]=0;
	FOR(x,A+1) FOR(y,B+1) {
		FOR(i,102) {
			// '('
			int nx=x;
			int ny=y;
			if(x<A && S[x]=='(') nx++;
			if(y<B && T[y]=='(') ny++;
			if(hoge[x][y][i]+1<hoge[nx][ny][i+1]) {
				hoge[nx][ny][i+1]=hoge[x][y][i]+1;
				from[nx][ny][i+1]={x,y,i,'('};
			}
			nx=x,ny=y;
			if(x<A && S[x]==')') nx++;
			if(y<B && T[y]==')') ny++;
			if(i && hoge[x][y][i]+1<hoge[nx][ny][i-1]) {
				hoge[nx][ny][i-1]=hoge[x][y][i]+1;
				from[nx][ny][i-1]={x,y,i,')'};
			}
		}
		for(i=100;i>=0;i--) {
			// '('
			int nx=x;
			int ny=y;
			if(x<A && S[x]=='(') nx++;
			if(y<B && T[y]=='(') ny++;
			if(hoge[x][y][i]+1<hoge[nx][ny][i+1]) {
				hoge[nx][ny][i+1]=hoge[x][y][i]+1;
				from[nx][ny][i+1]={x,y,i,'('};
			}
			nx=x,ny=y;
			if(x<A && S[x]==')') nx++;
			if(y<B && T[y]==')') ny++;
			if(i && hoge[x][y][i]+1<hoge[nx][ny][i-1]) {
				hoge[nx][ny][i-1]=hoge[x][y][i]+1;
				from[nx][ny][i-1]={x,y,i,')'};
			}
		}
	}
	
	x=A,y=B,i=0;
	while(hoge[x][y][i]) {
		s.push_back(from[x][y][i][3]);
		int nx=from[x][y][i][0];
		int ny=from[x][y][i][1];
		int ni=from[x][y][i][2];
		x=nx,y=ny,i=ni;
		
	}
	reverse(ALL(s));
	cout<<s<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}