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

int N,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	int ret=0;
	int cur=0,mi=0;
	FOR(i,N) {
		cin>>x;
		if(x!=0) {
			cur+=x;
			mi+=x;
		}
		else {
			if(cur<0) {
				ret++;
				cur=D;
			}
			mi=max(0,mi);
		}
		
		cur=min(cur,D);
		if(mi>D) return _P("-1\n");
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}