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
ll M;
vector<ll> A,B,AS,BS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>M;
	FOR(i,N) {
		cin>>x;
		if(x>M) A.push_back(x);
		else B.push_back(x);
	}
	sort(ALL(A));
	sort(ALL(B));
	reverse(ALL(A));
	reverse(ALL(B));
	AS.push_back(0);
	BS.push_back(0);
	FORR(x,A) AS.push_back(AS.back()+x);
	FORR(x,B) BS.push_back(BS.back()+x);
	
	ll ret=BS.back();
	for(i=1;i<=A.size();i++) {
		ll need=1LL*(i-1)*(D+1)+1;
		if(need>N) continue;
		ll v=AS[i]+BS[min((ll)B.size(),N-need)];
		ret=max(ret,v);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}