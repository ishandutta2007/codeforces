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

int N,M;
vector<int> S[252525];
vector<int> C;

int ok(int N) {
	int y,x;
	FOR(y,N+1) {
		int d=0;
		FOR(x,M) d+=C[x]!=S[y][x];
		if(d>2) return 0;
	}
	return 1;
}

void dfs(int cur) {
	vector<int> d;
	if(cur==N) {
		cout<<"Yes"<<endl;
		FORR(c,C) cout<<c<<" ";
		cout<<endl;
		exit(0);
	}
	
	int i;
	FOR(i,M) if(C[i]!=S[cur][i]) d.push_back(i);
	if(d.size()<=2) dfs(cur+1);
	if(d.size()==3) {
		FORR(v,d) {
			int p=C[v];
			C[v]=S[cur][v];
			if(ok(cur)) dfs(cur+1);
			C[v]=p;
		}
	}
	if(d.size()==4) {
		FORR(v1,d) {
			int p1=C[v1];
			C[v1]=S[cur][v1];
			FORR(v2,d) if(v1<v2) {
				int p2=C[v2];
				C[v2]=S[cur][v2];
				if(ok(cur)) dfs(cur+1);
				C[v2]=p2;
			}
			C[v1]=p1;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		FOR(j,M) cin>>x, S[i].push_back(x);
	}
	C=S[0];
	dfs(1);
	
	
	cout<<"No"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}