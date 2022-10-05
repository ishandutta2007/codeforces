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

int N,M;
vector<vector<int>> E;
int vis[1010];


pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	vis[cur]=1;
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E,int cur) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size(),-1);
	D[1].resize(E.size(),-1);
	auto v1=farthest(E,cur,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//
	for(int i=E.size()-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);
	//
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);

	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	E.resize(N+1);
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	vector<pair<int,int>> C;
	int ma=0;
	for(i=1;i<=N;i++) if(vis[i]==0) {
		auto d=diameter(E,i);
		ma=max(ma,d.first);
		C.push_back({(d.first+1)/2,d.second[0]});
	}
	if(C.size()==1) {
		cout<<ma<<endl;
		return;
	}
	sort(ALL(C));
	reverse(ALL(C));
	for(i=1;i<C.size();i++) C[i].first++;
	FORR(c,C) FORR(c2,C) if(c.second!=c2.second) ma=max(ma,c.first+c2.first);
	cout<<ma<<endl;
	for(i=1;i<C.size();i++) cout<<C[0].second<<" "<<C[i].second<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}