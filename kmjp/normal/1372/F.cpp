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
int A[202020];

map<int,int> hist;

pair<int,int> ask(int L,int R) {
	cout<<"? "<<L<<" "<<R<<endl;
	int X,F;
	cin>>X>>F;
	return {X,F};
}

int dfs(int L,int R) {
	if(L>R) return L-1;
	auto p=ask(L,R);
	
	
	int i;
	if(hist.count(p.first)) {
		int NL=R-p.second+1;
		int NR=NL+hist[p.first]-1;
		for(i=NL;i<=NR;i++) A[i]=p.first;
		hist.erase(p.first);
		dfs(L,NL-1);
		return NR;
	}
	else {
		hist[p.first]=p.second;
		while(hist.count(p.first)) {
			L=dfs(L,L+p.second-1)+1;
		}
		return dfs(L,R);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	dfs(1,N);
	
	cout<<"!";
	FOR(i,N) cout<<" "<<A[i+1];
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}