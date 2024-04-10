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

vector<ll> A,B;
ll S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x;
	A.resize(x);
	FOR(i,x) cin>>A[i], S+=A[i];
	cin>>x;
	B.resize(x);
	FOR(i,x) cin>>B[i], S-=B[i];
	if(S) return _P("-1\n");
	int ma=0;
	int cur[2]={};
	while(A.size()) {
		if(A.back()==B.back()) {
			A.pop_back();
			B.pop_back();
			ma++;
		}
		else if(A.back()<B.back()) {
			ll x=A.back();
			A.pop_back();
			A.back()+=x;
		}
		else if(A.back()>B.back()) {
			ll x=B.back();
			B.pop_back();
			B.back()+=x;
		}
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}