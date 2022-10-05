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


string S;
int N,K;

int lef[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	memset(lef,0x3f,sizeof(lef));
	
	cin>>N>>K;
	cin>>S;
	int dif=101010;
	int ma=1,a=0,b=0;
	lef[0][0]=lef[1][0]=-1;
	FOR(i,N) {
		if(S[i]=='a') lef[0][++a]=i;
		else lef[1][++b]=i;
		ma=max(ma,i+1-(lef[0][max(a-K,0)]+1));
		ma=max(ma,i+1-(lef[1][max(b-K,0)]+1));
		
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}