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

int N,M,L;
ll A[101010];
int cur=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N) {
		cin>>A[i+1];
		if(A[i+1]>L) {
			if(A[i]<=L) cur++;
		}
	}
	
	while(M--) {
		cin>>i;
		if(i==0) {
			cout<<cur<<endl;
		}
		else {
			cin>>x>>y;
			if(A[x]<=L && A[x]+y>L) {
				if(A[x-1]<=L && A[x+1]<=L) cur++;
				if(A[x-1]>L && A[x+1]>L) cur--;
			}
			A[x]+=y;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}