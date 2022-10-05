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
string S,R;
int mask[26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	FOR(i,N) {
		int m=0;
		for(j=S[i]-'a'+1;j<26;j++) m|=mask[j];
		if(m==3) return _P("NO\n");
		if(m==0 || m==1) {
			R+='1';
			mask[S[i]-'a'] |= 2;
		}
		else {
			R+='0';
			mask[S[i]-'a'] |= 1;
		}
	}
	
	cout<<"YES"<<endl;
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}