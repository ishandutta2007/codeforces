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
int A[101010];
ll S[101010];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>A[i],A[i]--;
	A[N-1]=N;
	set<pair<int,int>> L;
	L.insert({N-1,N});
	
	for(i=N-2;i>=0;i--) {
		
		while(L.begin()->second<=A[i]) L.erase(L.begin());
		auto it=L.lower_bound({A[i]+1,0});
		it--;
		x=it->first;
		S[i]=A[i]-i+S[x]-(A[i]-x)+N-1-A[i];
		L.insert({i,A[i]});
		ret += S[i];
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