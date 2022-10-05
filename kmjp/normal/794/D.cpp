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

ll N,M;
vector<int> E[303030];
int X[303030];
unordered_set<int> S[303030];

int num[1010101];


void dfs(int cur,int pre,int pre2);
void dfs2(int b,int a,int c) {
	assert(abs(X[b]-X[a])==1);
	assert(abs(X[b]-X[c])==1);
	assert(abs(X[a]-X[c])==2);
	FORR(e,E[b]) if(X[e]==0) {
		if(S[e].count(a) && S[e].count(c)) {
			X[e]=X[b];
			dfs2(e,a,c);
		}
		else if(S[e].count(a)) {
			X[e]=X[a];
			dfs(e,b,c);
		}
		else if(S[e].count(c)) {
			X[e]=X[c];
			dfs(e,b,a);
		}
		else {
			_P("NO\n");
			exit(0);
		}
	}
}
void dfs(int cur,int pre,int pre2) {
	assert(abs(X[cur]-X[pre2])==2);
	assert(abs(X[cur]-X[pre])==1);
	assert(abs(X[pre]-X[pre2])==1);
	FORR(e,E[cur]) if(X[e]==0) {
		if(S[e].count(pre)==0) {
			X[e]=2*X[cur]-X[pre];
			dfs(e,cur,pre);
		}
		else {
			if(S[e].count(pre2)==0) {
				X[e]=X[cur];
				dfs(e,pre,pre2);
			}
			else {
				X[e]=X[pre];
				dfs2(e,cur,pre2);
			}
		}
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		S[x-1].insert(y-1);
		S[y-1].insert(x-1);
	}
	
	if(M==N*(N-1)/2) {
		_P("YES\n");
		FOR(i,N) _P("1%c",(i==N-1)?'\n':' ');
		return;
	}
	int a=-1,b=-1,c=-1;
	FOR(i,N) {
		vector<int> V;
		FORR(e,E[i]) {
			FORR(v,V) if(S[e].count(v)==0) {
				a=e;
				c=v;
				break;
			}
			if(a>=0) break;
			V.push_back(e);
		}
		if(a>=0) {
			b=i;
			break;
		}
	}
	
	assert(a>=0);
	X[a]=500000-1;
	X[b]=500000;
	X[c]=500000+1;
	
	dfs2(b,a,c);
	dfs(c,b,a);
	dfs(a,b,c);
	
	FOR(i,N) num[X[i]]++;
	FOR(i,N) {
		if(E[i].size()+1 != num[X[i]]+num[X[i]+1]+num[X[i]-1]) {
			_P("NO\n");
			return;
		}
		FORR(e,E[i]) {
			if(abs(X[i]-X[e])>1) {
				_P("NO\n");
				return;
			}
		}
	}
	_P("YES\n");
	FOR(i,N) _P("%d%c",X[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}