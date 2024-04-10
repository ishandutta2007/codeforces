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
string S;
int M;
int B[1515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>S>>M;
		FOR(i,M) cin>>B[i];
		int C[26]={};
		FORR(c,S) C[c-'a']++;
		string T(M,'.');
		
		int z=25;
		while(1) {
			vector<int> cand;
			FOR(i,M) if(B[i]==0) {
				cand.push_back(i);
			}
			
			if(cand.empty()) break;
			while(C[z]<cand.size()) z--;
			FORR(c,cand) B[c]=-1, T[c]=z+'a';
			z--;
			FORR(c,cand) FOR(i,M) if(B[i]>0) B[i]-=abs(i-c);
			
		}
		
		cout<<T<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}