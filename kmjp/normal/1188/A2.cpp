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
vector<pair<int,int>> E[101010];
int X[1010],Y[1010];
ll V[1010];
vector<vector<ll>> R;



void go(int x,int y,ll v) {
	if(v==0) return;
	if(x==y) return;
	R.push_back({x,y,v});
}

int getl(int cur,int pre) {
	if(E[cur].size()==1) return cur;
	FORR(e,E[cur]) if(e.first!=pre) return getl(e.first,cur);
}

vector<int> leaf(int cur,int pre) {
	vector<int> L;
	
	if(E[cur].size()==1) {
		return {cur,cur};
	}
	else {
		FORR(e,E[cur]) if(e.first!=pre) L.push_back(getl(e.first,cur));
	}
	return L;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>X[i]>>Y[i]>>V[i];
		X[i]--;
		Y[i]--;
		E[X[i]].push_back({Y[i],i});
		E[Y[i]].push_back({X[i],i});
	}
	FOR(i,N) if(E[i].size()==2) return _P("NO\n");
	
	FOR(i,N-1) if(V[i]) {
		vector<int> L[2];
		L[0]=leaf(X[i],Y[i]);
		L[1]=leaf(Y[i],X[i]);
		ll v=V[i];
		go(L[0][0],L[1][0],v/2);
		go(L[0][1],L[1][1],v/2);
		go(L[0][0],L[0][1],-v/2);
		go(L[1][0],L[1][1],-v/2);
	}
	
	cout<<"YES"<<endl;
	cout<<R.size()<<endl;
	FORR(v,R) cout<<v[0]+1<<" "<<v[1]+1<<" "<<v[2]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}