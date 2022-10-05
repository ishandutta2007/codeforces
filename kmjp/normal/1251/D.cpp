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

int T;
int N;
ll S;
int L[202020],R[202020];

int ok(ll v) {
	int i;
	int num=0;
	vector<ll> V;
	FOR(i,N) {
		if(R[i]<v) continue;
		if(v<=L[i]) {
			num++;
		}
		else {
			V.push_back(v-L[i]);
		}
	}
	if(num+V.size()<(N+1)/2) return 0;
	sort(ALL(V));
	ll s=S;
	FOR(i,(N+1)/2-num) {
		s-=V[i];
	}
	return s>=0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			cin>>L[i]>>R[i];
			S-=L[i];
		}
		ll ret=0;
		for(i=50;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}