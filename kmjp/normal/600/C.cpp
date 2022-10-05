#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
int num[26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	FORR(r,S) num[r-'a']++;
	x=0,y=25;
	while(x<y) {
		while(x<26&&num[x]%2==0) x++;
		while(y>=0&&num[y]%2==0) y--;
		if(x>=y) break;
		num[x]++;
		num[y]--;
	}
	string T=S;
	x=0;
	FOR(i,26) {
		FOR(y,num[i]/2) T[x]=T[S.size()-1-x]='a'+i, x++;
		if(num[i]%2) T[S.size()/2]='a'+i;
	}
	cout<<T<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}