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

int N,T,K;
int A[202020];
int S[202020];
vector<pair<int,int>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>T>>K;
	int sum=0;
	A[0]=1;
	S[0]=1;
	for(i=1;i<=T;i++) {
		S[i]=S[i-1]+A[i-1];
		cin>>A[i];
		if(sum<N-1 && A[i]==0) return _P("-1\n");
		sum+=A[i];
		if(sum==N-1) T=i;
	}
	int maxleaf=1;
	int minleaf=0;
	for(i=0;i<=T;i++) {
		maxleaf += A[i]-1;
		minleaf += max(0,A[i]-A[i+1]);
	}
	if(K<minleaf || K>maxleaf) return _P("-1\n");
	K -= minleaf;
	for(i=1;i<=T;i++) {
		FOR(x,A[i]) {
			if(x>=A[i-1] || x==0) V.push_back({S[i-1],S[i]+x});
			else {
				if(K) {
					K--;
					V.push_back({S[i-1],S[i]+x});
				}
				else {
					V.push_back({S[i-1]+x,S[i]+x});
				}
			}
		}
	}
	_P("%d\n",N);
	FORR(r,V) _P("%d %d\n",r.first,r.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}