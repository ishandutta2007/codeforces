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
int T[1010],L[1010],R[1010];
int up[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>T[i]>>L[i]>>R[i];
		L[i]--,R[i]--;
		if(T[i]==1) {
			for(x=L[i];x<R[i];x++) up[x]=1;
		}
	}
	FOR(i,M) if(T[i]==0) {
		int ok=0;
		for(x=L[i];x<R[i];x++) if(up[x]==0) ok=1;
		if(ok==0) return _P("NO\n");
	}
	
	
	int cur=1010;
	cout<<"YES"<<endl;
	FOR(i,N) {
		cout<<cur<<" ";
		if(up[i]) cur++;
		else cur--;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}