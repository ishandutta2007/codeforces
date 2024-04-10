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
int P[101010];
vector<int> E[101010];
ll S[101010];
ll MS[101010];
ll A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	for(i=1;i<N;i++) {
		cin>>P[i];
		P[i]--;
		E[P[i]].push_back(i);
	}
	FOR(i,N) cin>>S[i];
	
	for(i=N-1;i>=0;i--) {
		MS[i]=-1;
		FORR(e,E[i]) if(MS[e]!=-1) {
			if(MS[i]==-1) MS[i]=MS[e];
			else MS[i]=min(MS[i],MS[e]);
		}
		
		if(MS[i]==-1) {
			MS[i]=S[i];
		}
		else {
			if(S[i]==-1) {
				S[i]=MS[i];
			}
			else {
				if(MS[i]<S[i]) return _P("-1\n");
				MS[i]=S[i];
			}
		}
	}
	
	if(S[0]==-1) return _P("0\n");
	
	ll sum=0;
	FOR(i,N) {
		if(S[i]>-1) {
			if(i==0) {
				A[i]=S[i];
			}
			else {
				A[i]=S[i]-S[P[i]];
			}
		}
		else {
			S[i]=S[P[i]];
		}
		sum+=A[i];
	}
	cout<<sum<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}