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

ll N;
int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	while(Q--) {
		cin>>y>>x;
		y--,x--;
		ll ret;
		if(N%2==0) {
			ret=(N/2)*y+x/2+1;
			if((x+y)%2) ret+=N*N/2;
		}
		else {
			if((x+y)%2==0) {
				ret=y/2*N+1;
				ret+=(x+N*(y%2))/2;
			}
			else {
				ret=y/2*N+1;
				ret+=(x+N*(y%2)-1)/2;
				ret+=(N*N+1)/2;
			}
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}