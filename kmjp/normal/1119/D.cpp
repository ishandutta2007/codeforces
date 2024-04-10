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

int N,Q;
ll S[101010];
vector<ll> D,DS;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	sort(S,S+N);
	FOR(i,N-1) D.push_back(S[i+1]-S[i]);
	sort(ALL(D));
	DS.push_back(0);
	FORR(d,D) DS.push_back(DS.back()+d);
	
	
	cin>>Q;
	while(Q--) {
		ll L,R,W;
		cin>>L>>R;
		W=R-L+1;
		
		x=lower_bound(ALL(D),W)-D.begin();
		ll ret=(N-1-x)*W+W+DS[x];
		cout<<ret<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}