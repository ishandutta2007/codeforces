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
vector<int> C[4];
vector<ll> S[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		C[x].push_back(y);
	}
	for(i=1;i<=3;i++) {
		sort(ALL(C[i]));
		reverse(ALL(C[i]));
		S[i].push_back(0);
		FORR(c,C[i]) S[i].push_back(S[i].back()+c);
	}
	
	int a=1,b=2,c=3;
	if(C[a].size()>C[b].size()) swap(a,b);
	if(C[b].size()>C[c].size()) swap(b,c);
	if(C[a].size()>C[b].size()) swap(a,b);
	
	S[c].clear();
	FOR(i,300005) S[c].push_back(-1LL<<60);
	S[c].push_back(0);
	FOR(i,C[c].size()) {
		FOR(x,c-1) S[c].push_back(S[c].back());
		S[c].push_back(S[c].back()+C[c][i]);
	}
	while(S[c].size()<=M+300005) S[c].push_back(S[c].back());
	
	ll ret=0;
	int as=C[a].size(), bs=C[b].size();
	for(i=0;i<=as;i++) {
		int w=M-i*a+300005;
		for(j=0;j<=bs;j++) {
			ret=max(ret,S[a][i]+S[b][j]+S[c][w]);
			w-=b;
		}
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}