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
char buf[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	sprintf(buf,"%X",N);
	int ret=0;
	FOR(i,10) {
		if(buf[i]=='0') ret++;
		if(buf[i]=='4') ret++;
		if(buf[i]=='6') ret++;
		if(buf[i]=='8') ret+=2;
		if(buf[i]=='9') ret++;
		if(buf[i]=='A') ret+=1;
		if(buf[i]=='B') ret+=2;
		if(buf[i]=='D') ret+=1;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}