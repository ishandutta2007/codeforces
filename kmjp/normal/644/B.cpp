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

int N,B;
ll ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B;
	deque<ll> D;
	FOR(i,N) {
		cin>>x>>y;
		while(D.size() && D.front()<=x) D.pop_front();
		
		if(D.size()==0) {
			ret[i]=x+y;
			D.push_back(ret[i]);
		}
		else if(D.size()<=B) {
			ret[i]=D.back()+y;
			D.push_back(ret[i]);
		}
		else {
			ret[i]=-1;
		}
	}
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}