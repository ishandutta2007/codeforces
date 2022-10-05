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


ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	map<int,int> M;
	for(i=2;i<=N;i++) {
		while(N%i==0) M[i]++, N/=i;
	}
	
	ll ret=1;
	int num=0;
	int ma=0;
	FORR(m,M) {
		ret*=m.first;
		if(m.second&(m.second-1)) num=1;
		ma=max(ma,m.second);
	}
	FORR(m,M) {
		if(ma!=m.second) num=1;
	}
	
	
	while(ma>1) {
		if(ma%2) ma++;
		ma/=2;
		num++;
	}
	cout<<ret<<" "<<num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}