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
map<int,int> M,L;
int from[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		if(M[A[i]]<M[A[i]-1]+1) {
			M[A[i]]=M[A[i]-1]+1;
			L[A[i]]=i;
			from[i]=L[A[i]-1];
		}
	}
	
	x=0;
	FORR(m,M) if(m.second>M[x]) x=m.first;
	cout<<M[x]<<endl;
	vector<int> V;
	V.push_back(L[x]);
	y=M[x]-1;
	FOR(i,y) {
		V.push_back(from[V.back()]);
	}
	reverse(ALL(V));
	FORR(v,V) cout<<(v+1)<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}