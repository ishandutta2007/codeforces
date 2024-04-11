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
ll a,b,c;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	if(S.back()=='f') a=1;
	if(S.back()=='e') a=2;
	if(S.back()=='d') a=3;
	if(S.back()=='a') a=4;
	if(S.back()=='b') a=5;
	if(S.back()=='c') a=6;
	S.pop_back();
	sscanf(S.c_str(),"%I64d",&b);
	b--;
	c = (b/4*16)+(b%2*7)+a;
	cout<<c<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}