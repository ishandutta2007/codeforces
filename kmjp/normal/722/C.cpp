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
int A[101010];
ll S[101010];
int P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	set<int> D;
	D.insert(0);
	D.insert(N+1);
	multiset<ll> MS;
	MS.insert(S[N]);
	FOR(i,N) {
		cin>>x;
		auto it=D.lower_bound(x);
		int ne=*it;
		it--;
		int pre=*it;
		
		ll su=S[ne-1]-S[pre];
		MS.erase(MS.find(su));
		if(x-pre>=2) MS.insert(S[x-1]-S[pre]);
		if(ne-x>=2) MS.insert(S[ne-1]-S[x]);
		
		D.insert(x);
		
		if(MS.empty()) cout<<0<<endl;
		else cout<<*MS.rbegin()<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}