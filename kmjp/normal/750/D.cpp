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
int T[55];
int dirx[9]={0,-1,-1,-1,0,1,1,1,0};
int diry[9]={1,1,0,-1,-1,-1,0,1,1};
int did[400][400];
int from[400][400];
int to[400][400];


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N;
	from[200][200]=1;
	FOR(i,N) {
		ZERO(to);
		cin>>r;
		if(i==0) r--;
		FOR(x,400) FOR(y,400) if(from[x][y]) {
			did[x][y]=1;
			FOR(z,8) if(from[x][y]&(1<<z)) {
				int tx=x,ty=y;
				FOR(j,r) {
					tx += dirx[z];
					ty += diry[z];
					did[tx][ty]=1;
				}
				to[tx][ty] |= (1<<((z+1)%8));
				to[tx][ty] |= (1<<((z+7)%8));
			}
		}
		swap(from,to);
	}
	int ret=0;
	FOR(x,400) FOR(y,400) ret+=did[x][y];
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}