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

int num[64];
string S;
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FOR(x,64) FOR(y,64) num[x&y]++;
	ll ret=1;
	FORR(r,S) {
		if(r>='0' && r<='9') r=r-'0';
		else if(r>='A' && r<='Z') r=10+r-'A';
		else if(r>='a' && r<='z') r=36+r-'a';
		else if(r=='-') r=62;
		else if(r=='_') r=63;
		ret = ret * num[r] % mo;
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