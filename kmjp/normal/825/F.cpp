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
int len[10101];
int sz[8080][8080];

int dp[8080];

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,10000) len[i]=4;
	FOR(i,1000) len[i]=3;
	FOR(i,100) len[i]=2;
	FOR(i,10) len[i]=1;
	
	cin>>S;
	N=S.size();
	
	FOR(y,N+1) FOR(x,y) sz[x][y]=10000;
	FOR(x,N) {
		auto Z=Zalgo(S.substr(x));
		for(i=1;x+i<=N;i++) {
			for(y=1;x+i*y<=N;y++) {
				if(Z[i*(y-1)]<i) break;
				sz[x][x+i*y]=min(sz[x][x+i*y],len[y]+i);
			}
		}
	}
	dp[0]=0;
	for(i=1;i<=N;i++) {
		dp[i]=101010;
		FOR(j,i) dp[i]=min(dp[i],dp[j]+sz[j][i]);
	}
	cout<<dp[N]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}