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
int L[1010],R[1010];

int A[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>R[i];
	
	for(i=N;i>=1;i--) {
		vector<int> V;
		FOR(x,N) if(L[x]==0 && R[x]==0 && A[x]==0) V.push_back(x);
		FORR(v,V) {
			A[v]=i;
		}
		FORR(v,V) {
			FOR(x,N) {
				if(x<v && A[x]==0) R[x]--;
				if(x>v && A[x]==0) L[x]--;
			}
		}
	}
	
	FOR(x,N) if(A[x]==0) return _P("NO\n");
	cout<<"YES"<<endl;
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}