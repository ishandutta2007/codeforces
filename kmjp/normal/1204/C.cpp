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
int A[101][101];
int F[101][101];

int M;
int V[1010101];
int dp[1010101];
int from[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S;
		FOR(x,N) {
			A[y][x]=S[x]-'0';
			if(y!=x && A[y][x]==0) A[y][x]=202;
		}
	}
	
	FOR(i,N) FOR(x,N) FOR(y,N) A[x][y]=min(A[x][y],A[x][i]+A[i][y]);
	FOR(x,N) FOR(y,N) if(x!=y && A[x][y]<=100) {
		int num=0;
		FOR(i,N) if(i!=x && i!=y && A[x][i]+A[i][y]==A[x][y]) num++;
		F[x][y]=(num==A[y][x]-1);
	}
	
	cin>>M;
	FOR(i,M) {
		cin>>V[i];
		V[i]--;
		if(i) {
			from[i]=i-1;
			dp[i]=dp[from[i]]+1;
			
			for(j=1;j<=N&&i-j>=0;j++) {
				if(dp[i-j]+1<dp[i] && A[V[i-j]][V[i]]==j) {
					dp[i]=dp[i-j]+1;
					from[i]=i-j;
				}
			}
		}
	}
	
	vector<int> C;
	int cur=M-1;
	while(cur>0) {
		C.push_back(V[cur]+1);
		cur=from[cur];
	}
	C.push_back(V[0]+1);
	reverse(ALL(C));
	
	cout<<C.size()<<endl;
	FORR(c,C) cout<<c<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}