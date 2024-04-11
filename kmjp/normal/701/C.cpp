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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	map<char,int> M;
	FORR(c,S) M[c]=0;
	x=0;
	FORR(r,M) r.second = x++;
	vector<int> V(M.size(),-1000000);
	int mi=101010;
	FOR(i,N) {
		V[M[S[i]]]=i;
		int mimi=i;
		FORR(r,V) mimi=min(mimi,r);
		mi=min(mi,i-mimi+1);
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}