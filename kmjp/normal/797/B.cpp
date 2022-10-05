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
ll A[101010];
ll ma[2]={-1LL<<30,(-1LL<<30)-1};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll ret=-1<<30;
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		
		if(A[i]%2==0) {
			ma[0]=max({ma[0],A[i],ma[0]+A[i]});
			ma[1]=max({ma[1],ma[1]+A[i]});
		}
		else {
			ll om=ma[0];
			ma[0]=max({ma[0],ma[1]+A[i]});
			ma[1]=max({ma[1],A[i],om+A[i]});
		}
	}
	
	cout<<ma[1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}