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
ll A,B,C,D;
map<pair<ll,ll>,vector<int>> cand;
set<pair<int,int>> E[404040];
vector<int> V[404040];

vector<pair<int,int>> R;

int dfs(int cur,int pe) {
	int oth=-1;
	while(E[cur].size()) {
		int tar=E[cur].begin()->first;
		int e=E[cur].begin()->second;
		E[cur].erase(E[cur].begin());
		E[tar].erase({cur,e});
		e=dfs(tar,e);
		if(e!=-1) {
			if(oth==-1) {
				oth=e;
			}
			else {
				R.push_back({e+1,oth+1});
				oth=-1;
			}
		}
	}
	if(oth==-1) {
		return pe;
	}
	else if(pe!=-1) {
		R.push_back({pe+1,oth+1});
		return -1;
	}
	else return -1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A>>B>>C>>D;
		ll p=C*B;
		ll q=D*(A+B);
		ll g=__gcd(p,q);
		cand[{p/g,q/g}].push_back(i);
		p=(C+D)*B;
		q=D*A;
		g=__gcd(p,q);
		cand[{p/g,q/g}].push_back(i);
	}
	
	x=0;
	FORR2(c,v,cand) {
		FORR(e,v) V[e].push_back(x);
		x++;
	}
	FOR(i,N) {
		E[V[i][0]].insert({V[i][1],i});
		E[V[i][1]].insert({V[i][0],i});
	}
	
	FOR(i,404040) dfs(i,-1);
	cout<<R.size()<<endl;
	FORR2(a,b,R) cout<<a<<" "<<b<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}