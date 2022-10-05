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

int T;
string S;
int from[4][4];
int to[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>T;
	while(T--) {
		cin>>S;
		
		FOR(x,4) FOR(y,4) from[x][y]=101010;
		from[0][0]=0;
		FORR(c,S) {
			FOR(x,4) FOR(y,4) to[x][y]=101010;
			FOR(x,4) FOR(y,4) {
				{
					int nx=x,ny=y;
					// '0';
					if(x==0 || x==2) nx++;
					if(y==1) ny++;
					to[nx][ny]=min(to[nx][ny],from[x][y]+(c!='0'));
				}
				{
					int nx=x,ny=y;
					// '1';
					if(x==1) nx++;
					if(y==0 || y==2) ny++;
					to[nx][ny]=min(to[nx][ny],from[x][y]+(c!='1'));
				}
			}
			swap(from,to);
		}
		int mi=10101010;
		FOR(x,3) FOR(y,3) mi=min(mi,from[x][y]);
		cout<<mi<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}