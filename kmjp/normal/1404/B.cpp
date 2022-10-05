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
int N,A,B,DA,DB;
vector<int> E[101010];

int D[101010];

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);
	//
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);

	return R;
}

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>DA>>DB;
		A--,B--;
		FOR(i,N) {
			E[i].clear();
			D[i]=1<<20;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		if(DB<=DA*2) {
			cout<<"Alice"<<endl;
			continue;
		}
		dfs(A,A,0);
		if(D[B]<=DA) {
			cout<<"Alice"<<endl;
			continue;
		}
		auto R=diameter();
		if(R.first<=2*DA) {
			cout<<"Alice"<<endl;
		}
		else {
			cout<<"Bob"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}