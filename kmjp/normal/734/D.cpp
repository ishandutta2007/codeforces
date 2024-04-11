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
ll TX,TY;
char T[505050];
ll X[505050],Y[505050];
vector<pair<ll,char>> V[9];

int type(int x,int y) {
	if(x==0) {
		return (y<0);
	}
	else if(y==0) {
		return 2+(x<0);
	}
	else if(abs(x)==abs(y)) {
		if(x>0 && y>0) return 4;
		if(x>0 && y<0) return 5;
		if(x<0 && y>0) return 6;
		if(x<0 && y<0) return 7;
	}
	return 8;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>TX>>TY;
	FOR(i,N) {
		cin>>T[i]>>X[i]>>Y[i];
		X[i]-=TX;
		Y[i]-=TY;
		
		V[type(X[i],Y[i])].push_back({abs(X[i])+abs(Y[i]),T[i]});
	}
	
	FOR(i,8) if(V[i].size()) {
		sort(ALL(V[i]));
		if(i<4 && V[i][0].second == 'R') return _P("YES\n");
		if(i>=4 && V[i][0].second == 'B') return _P("YES\n");
		if(V[i][0].second == 'Q') return _P("YES\n");
	}
	_P("NO\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}