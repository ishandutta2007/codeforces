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

int A,TA,B,TB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>TA;
	cin>>B>>TB;
	cin>>s;
	int st=(s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0')-5*60;
	int ed=st+TA;
	int ret=0;
	for(i=0;i<19*60;i+=B) {
		int ed2=i+TB;
		if(i<ed && ed2>st) ret++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}