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

int U[101010],V[101010];
int C[101010];
vector<int> E[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	FOR(i,N) cin>>C[i];
	
	int num=0;
	FOR(i,N-1) if(C[U[i]]!=C[V[i]]) num++;
	FOR(i,N) {
		int x=0;
		FORR(e,E[i]) if(C[i]!=C[e]) x++;
		if(x==num) {
			cout<<"YES"<<endl;
			cout<<i+1<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}