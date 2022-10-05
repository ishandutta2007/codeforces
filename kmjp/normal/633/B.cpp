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

vector<int> R;
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int num=0;
	for(i=1;i<=1000000;i++) {
		x=i;
		while(x%5==0) num++, x/=5;
		if(num==N) R.push_back(i);
	}
	
	_P("%d\n",R.size());
	FOR(i,R.size()) _P("%d%s",R[i],(i==R.size()-1)?"\n":" ");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}