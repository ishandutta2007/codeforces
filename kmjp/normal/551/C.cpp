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

int N,M;
ll A[101010];
ll B[101010];

bool ok(ll V) {
	int i;
	memmove(B,A,sizeof(B));
	
	int cur=N-1;
	FOR(i,M) {
		ll v=V;
		while(cur>=0 && B[cur]==0) cur--;
		if(cur<0) return true;
		v-=(cur+1);
		if(v<0) return false;
		while(cur>=0 && v>0) {
			if(B[cur]>v) {
				B[cur]-=v;
				break;
			}
			v-=B[cur--];
		}
	}
	while(cur>=0 && B[cur]==0) cur--;
	return cur<0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ok(ret-(1LL<<i))) ret -= 1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}