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



int M;
vector<int> A[201010];
set<pair<int,int>> E[404040];
string R;

void dfs(int cur) {
	if(E[cur].size()) {
		auto p=*E[cur].begin();
		E[cur].erase(p);
		E[p.first].erase({cur,p.second});
		if(cur<200000) R[p.second]='R';
		dfs(p.first);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,int> mp;
	scanf("%d",&M);
	FOR(i,M) {
		scanf("%d",&x);
		FOR(j,x) {
			scanf("%d",&y);
			mp[y]=0;
			A[i].push_back(y);
		}
	}
	
	x=0;
	FORR2(a,b,mp) mp[a]=x++;
	FOR(i,M) {
		FORR(j,A[i]) {
			j=mp[j];
			E[i].insert({200000+j,R.size()});
			E[200000+j].insert({i,R.size()});
			R+='L';
		}
		R+='\n';
	}
	
	FOR(i,400000) if(E[i].size()%2) {
		cout<<"NO"<<endl;
		return;
	}
	FOR(i,400000) dfs(i);
	
	cout<<"YES"<<endl;
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}