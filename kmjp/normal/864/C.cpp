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

ll A,B,F,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>F>>K;
	
	vector<ll> cand;
	
	cand.push_back(0);
	FOR(i,K) {
		if(i%2==0) cand.push_back(A*i+F);
		else cand.push_back(A*(i+1)-F);
	}
	cand.push_back(A*K);
	
	ll ret=0;
	ll cur=B;
	FOR(i,cand.size()-1) {
		ll dist=cand[i+1]-cand[i];
		if(dist>B) return _P("-1\n");
		
		if(dist>cur) {
			cur=B;
			ret++;
		}
		cur-=dist;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}