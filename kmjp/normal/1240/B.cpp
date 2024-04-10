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

int Q;
int N;
int A[303030];
int L[303030];
int R[303030];
int C[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		vector<int> V;
		
		FOR(i,N) {
			cin>>A[i];
			V.push_back(A[i]);
		}
		sort(ALL(V));
		V.erase(unique(ALL(V)),V.end());
		FOR(i,V.size()) {
			R[i]=C[i]=0;
			L[i]=1<<30;
		}
		FOR(i,N) {
			A[i]=lower_bound(ALL(V),A[i])-V.begin();
			R[A[i]]=i;
			L[A[i]]=min(L[A[i]],i);
		}
		
		int ma=0;
		FOR(i,N) if(L[A[i]]==i) {
			if(A[i]==0) C[A[i]]=0;
			else {
				if(R[A[i]-1]<i) C[A[i]]=C[A[i]-1]+1;
				else C[A[i]]=0;
			}
			ma=max(ma,C[A[i]]);
		}
		
		
		
		cout<<V.size()-(ma+1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}