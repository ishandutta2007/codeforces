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
string S;
ll mo=1000000007;
int len[5050][5050];
int num[5050][5050];
int sum[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	for(y=N-1;y>=0;y--) {
		for(x=y-1;x>=0;x--) {
			if(S[x]<S[y]) {
				len[x][y]=1;
			}
			else if(S[x]==S[y]) {
				if(y==N-1) len[x][y]=505050;
				else len[x][y]=len[x+1][y+1]+1;
			}
			else {
				len[x][y]=505050;
			}
		}
	}
	FOR(x,N) num[0][x]=1, sum[1][x]=1;
	for(x=1;x<N;x++) {
		if(S[x]=='0') {
			for(y=x;y<N;y++) sum[x+1][y]=sum[x][y];
		}
		else {
			for(y=x;y<N;y++) {
				l=y-x+1;
				int px=x-l;
				if(px>=0 && len[px][x]>l) px++;
				px=max(px,0);
				num[x][y] = sum[x][x-1]-sum[px][x-1];
				if(num[x][y]<0) num[x][y]+=mo;
				sum[x+1][y]=sum[x][y]+num[x][y];
				if(sum[x+1][y]>=mo) sum[x+1][y]-=mo;
			}
		}
	}
	ll ret=0;
	FOR(x,N) ret+=num[x][N-1];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}