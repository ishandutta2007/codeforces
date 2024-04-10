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

int N,K;
vector<int> E[101010];
int D[101010];
vector<int> Ds[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	if(N==1) return _P("No\n");
	
	queue<int> Q;
	FOR(i,N) {
		D[i]=101010;
		if(E[i].size()==1) {
			D[i]=0;
			Q.push(i);
		}
	}
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		Ds[D[x]].push_back(x);
		FORR(e,E[x]) if(D[e]>D[x]+1) {
			D[e]=D[x]+1;
			Q.push(e);
		}
	}
	if(K>100000 || Ds[K].size()!=1) return _P("No\n");
	x=0;
	for(i=K+1;i<=101000;i++) x+=Ds[i].size();
	if(x) return _P("No\n");
	
	FOR(i,N) if(D[i]) {
		int num=0;
		FORR(e,E[i]) {
			if(D[e]==D[i]+1) continue;
			else if(D[e]==D[i]-1) num++;
			else return _P("No\n");
		}
		if(num<3) return _P("No\n");
	}
	_P("Yes\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}