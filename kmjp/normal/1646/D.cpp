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

int N;
vector<int> E[202020];
ll num[202020][2];
ll sum[202020][2];
vector<int> memo[202020];
int S[202020];
void dfs(int cur,int pre) {
	num[cur][1]=1;
	sum[cur][1]=E[cur].size();
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		num[cur][1]+=num[e][0];
		sum[cur][1]+=sum[e][0];
		
		if(num[e][0]>num[e][1]||(num[e][0]==num[e][1]&&sum[e][0]<sum[e][1])) {
			num[cur][0]+=num[e][0];
			sum[cur][0]+=sum[e][0];
			memo[cur].push_back(0);
		}
		else {
			num[cur][0]+=num[e][1];
			sum[cur][0]+=sum[e][1];
			memo[cur].push_back(1);
		}
		
	}
}
void dfs2(int cur,int pre,int t) {
	if(t==1) {
		S[cur]=E[cur].size();
		FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,0);
	}
	else {
		S[cur]=1;
		reverse(ALL(memo[cur]));
		FORR(e,E[cur]) if(e!=pre) {
			dfs2(e,cur,memo[cur].back());
			memo[cur].pop_back();
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	if(N==2) {
		cout<<"2 2"<<endl;
		cout<<"1 1"<<endl;
		return;
	}
	
	dfs(0,0);
	
	if(num[0][0]>num[0][1]||(num[0][0]==num[0][1]&&sum[0][0]<sum[0][1])) {
		x=0;
	}
	else {
		x=1;
	}
	dfs2(0,0,x);
	cout<<num[0][x]<<" ";
	y=0;
	FOR(i,N) y+=S[i];
	cout<<y<<endl;
	FOR(i,N) cout<<S[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}