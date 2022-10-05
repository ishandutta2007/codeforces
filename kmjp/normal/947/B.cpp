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
ll V[101010],T[101010];
ll ST[101010];

int keep[101010];
ll del[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i+1];
	FOR(i,N) {
		cin>>T[i];
		ST[i+1]=ST[i]+T[i];
	}
	ST[N+1]=1LL<<40;
	for(i=1;i<=N;i++) {
		ll v=V[i]+ST[i-1];
		x=lower_bound(ST,ST+N+1,v)-ST;
		del[x]+=v-ST[x-1];
		keep[i]++;
		keep[x]--;
	}
	for(i=1;i<=N;i++) {
		keep[i]+=keep[i-1];
		ll tot=1LL*keep[i]*T[i-1]+del[i];
		cout<<tot<<" ";
		
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}