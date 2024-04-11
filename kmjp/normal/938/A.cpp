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

void solve() {
	int i,j,k,l,r,x,y; string s;
	map<char,int> M;
	
	M['a']=1;
	M['i']=1;
	M['u']=1;
	M['e']=1;
	M['o']=1;
	M['y']=1;
	
	
	cin>>N>>S;
	string R;
	char pre='0';
	FORR(c,S) {
		if(M[c]==0 || M[pre]==0) {
			R+=c;
			pre=c;
		}
	}
	cout<<R<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}