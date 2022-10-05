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
string S;
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		FOR(i,N) R[i]=N-i;
		FOR(i,N-1) if(S[i]=='<') {
			j=i;
			while(j<N-1&&S[j]=='<') j++;
			reverse(R+i,R+j+1);
			i=j;
		}
		FOR(i,N) cout<<R[i]<<" ";
		cout<<endl;
		
		vector<int> A;
		A.push_back(1);
		FOR(i,N-1) {
			if(S[i]=='<') A.push_back(0);
			A.back()++;
		}
		
		int cur=0;
		FORR(r,A) {
			cur+=r;
			FOR(i,r) cout<<cur--<<" ";
			cur+=r;
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}