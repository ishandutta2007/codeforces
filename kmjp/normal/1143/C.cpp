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
vector<int> E[202020];
int C[202020];
int NG[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int R;
	cin>>N;
	FOR(i,N) {
		cin>>x>>C[i];
		if(x==-1) R=i;
		else E[x-1].push_back(i);
	}
	int num=0;
	FOR(i,N) if(C[i]) {
		int ng=0;
		FORR(c,E[i]) if(C[c]==0) ng=1;
		if(ng==0) {
			num++;
			cout<<(i+1)<<" ";
		}
	}
	if(num==0) cout<<-1;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}