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

int T;
int N;
int A[1010];
int S[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		vector<int> V;
		
		while(1) {
			int ok=1;
			ZERO(S);
			FOR(i,N) if(A[i]!=i) ok=0;
			if(ok) break;
			FOR(i,N) S[A[i]]++;
			int mex=0;
			while(S[mex]) mex++;
			if(mex<N) {
				V.push_back(mex);
				A[mex]=mex;
			}
			else {
				FOR(i,N) if(A[i]!=i) break;
				FOR(j,N) if(A[j]==i) {
					V.push_back(j);
					A[j]=mex;
				}
			}
			/*
			cout<<"!"<<mex<<"  ";
			FOR(i,N) cout<<A[i];
			cout<<endl;
			*/
		}
		
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v+1<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}