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
string S;

int cons[256];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,256) cons[i]=1;
	cons['a']=0;
	cons['i']=0;
	cons['u']=0;
	cons['e']=0;
	cons['o']=0;
	
	
	cin>>S;
	string T;
	int hoge=0;
	FOR(i,S.size()) {
		char c=S[i];
		if(cons[c]==0) hoge=0;
		else hoge++;
		if(hoge>=3) {
			if(S[i]==S[i-1] && S[i]==S[i-2]) {
				hoge=3;
			}
			else {
				hoge=1;
				T+=' ';
			}
		}
		T+=c;
	}
	cout<<T<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}