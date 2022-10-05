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
ll M;
ll A[602020];
ll S[602020];

ll hoge(ll v) {
	v=min(v,(ll)N);
	
	ll sum=0;
	int cur=0;
	int step=0;
	while(cur<N) {
		if(A[cur]<=step) break;
		if(A[cur+v-1]>=step) {
			sum+=S[cur+v]-S[cur]-step*v;
			cur+=v;
			step++;
		}
		else {
			while(A[cur]>step) sum+=A[cur]-step,cur++;;
			break;
		}
	}
	return sum;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	reverse(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i];
	
	ll mi=1LL<<40;
	if(hoge(mi)<M) return _P("-1\n");
	
	for(i=39;i>=0;i--) if(hoge(mi-(1LL<<i))>=M) mi-=1LL<<i;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}