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
int A[202020],T[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	map<int,vector<int>> M;
	FOR(i,N) {
		cin>>T[i];
		M[A[i]].push_back(T[i]);
	}
	
	priority_queue<int> P;
	ll ret=0;
	ll sum=0;
	int pre=-1000000;
	FORR(m,M) {
		while(pre<m.first && P.size()) {
			sum-=P.top();
			ret+=sum;
			P.pop();
			pre++;
		}
		pre=m.first;
		FORR(a,m.second) {
			P.push(a);
			sum+=a;
		}
	}
	
	while(P.size()) {
		sum-=P.top();
		ret+=sum;
		P.pop();
	}
	cout<<ret<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}