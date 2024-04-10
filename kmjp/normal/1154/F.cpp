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

int N,M,K;
ll A[202020],S[202020];
int BE[202020];

pair<int,int> P[202020];

bool cmp(pair<int,int> P,pair<int,int> Q) {
	return P.first*Q.second<Q.first*P.second;
}

ll co[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	reverse(A,A+K);
	FOR(i,K) S[i+1]=S[i]+A[i];
	
	FOR(i,M) {
		cin>>x>>y;
		BE[x]=max(BE[x],y);
	}
	FOR(i,K) P[i]={i+1,BE[i+1]};
	sort(P,P+K,cmp);
	
	FOR(i,K) co[i+1]=1LL<<60;
	
	FOR(i,K) {
		FOR(j,K) if(j+P[i].first<=K) {
			co[j+P[i].first]=min(co[j+P[i].first],co[j]+S[j+P[i].first-P[i].second]-S[j]);
		}
	}
	cout<<co[K]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}