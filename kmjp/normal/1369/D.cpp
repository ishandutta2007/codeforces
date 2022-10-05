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
const ll mo=1000000007;
ll from[2][3],to[2][3];

ll pat[2020202][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=3;i<=2000000;i++) {
		ll a,b;
		if((i-1)%3==0) a=pat[i-1][1];
		else a=pat[i-1][0];
		if((i-2)%3==0) b=pat[i-2][1];
		else b=pat[i-2][0];
		
		
		pat[i][0]=(a+2*b)%mo;
		pat[i][1]=(pat[i-1][0]+2*pat[i-2][0]+4)%mo;
		
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N%3==0) cout<<pat[N][1]<<endl;
		else cout<<pat[N][0]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}