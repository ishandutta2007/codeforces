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


int id=1;
int nex[505][10];
int D[555];
int val[555];
int memo[555][555][12];

int N,K;
string S[505];
int M[505];

int dfs(int cur,int pd,int K) {
	if(memo[cur][pd][K]>=0) return memo[cur][pd][K];
	
	int dp[11]={};
	int i,j,k;
	FOR(i,10) if(nex[cur][i]>=0) {
		int tmp[11]={},tmp2[11]={};
		FOR(j,11) tmp[j]=dfs(nex[cur][i],pd,j);
		FOR(j,11) tmp2[j]=1<<30;
		FOR(j,11) FOR(k,11) if(j+k<=10) tmp2[j+k]=min(tmp2[j+k],dp[j]+tmp[k]);
		swap(dp,tmp2);
	}
	
	int ret=dp[K]+val[cur]*(D[cur]-pd);
	
	// take here
	if(K>0) ret=min(ret,dfs(cur,D[cur],K-1));
	
	return memo[cur][pd][K]=ret;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	MINUS(nex);
	FOR(i,N) {
		cin>>S[i]>>M[i];
		int cur=0;
		FORR(s,S[i]) {
			s-='0';
			if(nex[cur][s]==-1) {
				nex[cur][s]=id++;
				D[nex[cur][s]]=D[cur]+1;
			}
			cur=nex[cur][s];
		}
		val[cur]+=M[i];
	}
	
	MINUS(memo);
	cout<<dfs(0,0,K)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}