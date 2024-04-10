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
int Q;

multiset<int> S;
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	FORR(m,M) if(m.second>=2) S.insert(-m.second);
	
	cin>>Q;
	while(Q--) {
		cin>>s>>x;
		if(M[x]>=2) S.erase(S.find(-M[x]));
		if(s=="+") M[x]++;
		else M[x]--;
		if(M[x]>=2) S.insert(-M[x]);
		
		vector<int> V;
		FORR(m,S) {
			V.push_back(-m);
			if(V.size()>=3) break;
		}
		V.push_back(0);
		V.push_back(0);
		V.push_back(0);
		int ok=0;
		if(V[0]>=4) {
			V[0]-=4;
			if(V[0]>=4 || V[1]>=4 || V[2]>=4) ok=1;
			if((V[0]>=2)+(V[1]>=2)+(V[2]>=2)>=2) ok=1;
		}
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
			
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}