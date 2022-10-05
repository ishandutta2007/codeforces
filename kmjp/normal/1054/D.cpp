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

int N,K,NK;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	NK=(1<<K)-1;
	
	ll tot=0;
	int cur=0;
	map<int,ll> M;
	M[0]=1;
	FOR(i,N) {
		cin>>x;
		if(M[cur^x]<M[cur^x^NK]) {
			cur^=x;
		}
		else {
			cur^=x^NK;
		}
		tot+=(i+1)-M[cur];
		M[cur]++;
	}
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}