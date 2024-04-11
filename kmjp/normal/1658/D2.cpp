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
ll L,R;

int dfs(int cur,int L,int R,vector<int> A) {
	int C[2]={},D[2]={};
	int i,j;
	if(A.empty()||cur<0) return 0;
	
	int NL[2]={1<<30,1<<30};
	int NR[2]={-1<<30,-1<<30};
	for(i=L;i<=R;i++) {
		C[(i>>cur)%2]++;
		if(i&(1<<cur)) {
			NL[1]=min(NL[1],i);
			NR[1]=max(NR[1],i);
		}
		else {
			NL[0]=min(NL[0],i);
			NR[0]=max(NR[0],i);
		}
	}
	FORR(a,A) D[(a>>cur)%2]++;
	int ret=0;
	if(C[0]!=D[0]) {
		ret|=1<<cur;
		FORR(a,A) a^=1<<cur;
	}
	
	vector<int> X[2];
	FORR(a,A) X[(a>>cur)%2].push_back(a);
	
	return ret|dfs(cur-1,NL[0],NR[0],X[0])|dfs(cur-1,NL[1],NR[1],X[1]);
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		vector<int> A;
		for(i=L;i<=R;i++) {
			cin>>x;
			A.push_back(x);
		}
		
		cout<<dfs(16,L,R,A)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}