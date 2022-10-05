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
int A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V[2];
		FOR(i,2*N) {
			cin>>A[i];
			V[A[i]%2].push_back(i+1);
		}
		
		if(V[0].size()%2==0 && V[1].size()%2==0) {
			if(V[0].size()) V[0].pop_back(),V[0].pop_back();
			else V[1].pop_back(),V[1].pop_back();
		}
		else {
			V[0].pop_back();
			V[1].pop_back();
		}
		
		FOR(i,2) FOR(j,V[i].size()/2) cout<<V[i][2*j]<<" "<<V[i][2*j+1]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}