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

int A;
int N;
int P[404040];

bitset<4040> F,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	while(A--) {
		cin>>N;
		FOR(i,2*N) cin>>P[i];
		vector<int> V;
		int cur=0;
		while(cur<2*N) {
			x=cur+1;
			while(x<2*N&&P[cur]>P[x]) x++;
			V.push_back(x-cur);
			cur=x;
		}
		
		F.reset();
		F[0]=1;
		FORR(c,V) {
			F|=F<<c;
		}
		if(F[N]) {
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