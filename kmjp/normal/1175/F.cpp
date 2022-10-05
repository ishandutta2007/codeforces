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
int A[303030];

pair<ll,ll> H[303030];
pair<ll,ll> HS[303030];
pair<ll,ll> S[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	mt19937 mt(time(0));
	
	for(i=1;i<=300000;i++) {
		H[i].first=HS[i].first=mt();
		H[i].second=HS[i].second=mt();
		HS[i].first^=HS[i-1].first;
		HS[i].second^=HS[i-1].second;
	}
	
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	ll ret=0;
	
	FOR(x,2) {
		FOR(i,N) {
			S[i+1].first=S[i].first^H[A[i]].first;
			S[i+1].second=S[i].second^H[A[i]].second;
		}
		FOR(i,N) if(A[i]==1) {
			int ma=0;
			for(j=i+1;j<N;j++) {
				if(A[j]==1) break;
				ma=max(ma,A[j]);
				if(j>=ma-1) {
					if((S[j+1].first^S[j+1-ma].first)==HS[ma].first && (S[j+1].second^S[j+1-ma].second)==HS[ma].second) ret++;
				}
			}
		}
		reverse(A,A+N);
	}
	FOR(i,N) if(A[i]==1) ret++;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}