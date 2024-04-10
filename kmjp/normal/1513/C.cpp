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

int T;
int S;
int M;
const int mo=1000000007;
int num[10][11][200001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10) num[i][i][0]=1;
	for(i=1;i<=200000;i++) {
		FOR(x,10) {
			FOR(y,9) {
				(num[x][y+1][i]+=num[x][y][i-1])%=mo;
			}
			(num[x][1][i]+=num[x][9][i-1])%=mo;
			(num[x][0][i]+=num[x][9][i-1])%=mo;
			FOR(y,10) (num[x][10][i]+=num[x][y][i])%=mo;
		}
	}
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&S,&M);
		ll ret=0;
		while(S) {
			ret+=num[S%10][10][M];
			S/=10;
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}