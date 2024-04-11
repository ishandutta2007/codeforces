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

vector<int> A={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<int> B={4,9,25,49};

string ask(int v) {
	string s;
	cout<<v<<endl;
	cin>>s;
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int yes=0;
	FORR(r,A) if(ask(r)=="yes") yes++;
	FORR(r,B) if(ask(r)=="yes") yes+=2;
	
	if(yes<=1) cout<<"prime"<<endl;
	else cout<<"composite"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}