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

int T,N,M;
ll E[555][555];
int D[555][555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(y,N) FOR(x,N) {
			E[y][x]=(x==y)?0:1LL<<60;
			D[y][x]=(x==y)?0:1LL<<20;
		}
		
		FOR(i,M) {
			cin>>x>>y>>r;
			x--,y--;
			E[x][y]=min(E[x][y],(ll)r);
			E[y][x]=min(E[y][x],(ll)r);
			D[x][y]=D[y][x]=1;
		}
		
		FOR(k,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],D[x][k]+D[k][y]);
		
		ll mi=1LL<<60;
		FOR(x,N) FOR(y,N) if(x!=y&&E[x][y]!=1LL<<60) {
			int step=min(D[0][x]+D[N-1][y],D[N-1][x]+D[0][y]);
			FOR(k,N) step=min(step,D[x][k]+1+D[k][0]+D[k][N-1]);
			//cout<<step<<" "<<E[x][y]<<endl;
			mi=min(mi,(step+1)*E[x][y]);
		}
		
		
		FOR(k,N) FOR(x,N) FOR(y,N) E[x][y]=min(E[x][y],E[x][k]+E[k][y]);
		mi=min(mi,E[0][N-1]);
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}