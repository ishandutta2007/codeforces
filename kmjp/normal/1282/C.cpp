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

int M;
int N,T,A,B;
pair<int,int> P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	while(M--) {
		cin>>N>>T>>A>>B;
		int C[2]={};
		FOR(i,N) cin>>P[i].second;
		FOR(i,N) {
			cin>>P[i].first;
			C[P[i].second]++;
		}
		sort(P,P+N);
		P[N]={T+1,0};
		ll tot=0;
		int ma=0;
		
		if(tot<P[0].first) {
			int lef=P[0].first-1-tot;
			int ret=0;
			int a=min(C[0],lef/A);
			ret+=a;
			lef-=a*A;
			a=min(C[1],lef/B);
			ma=max(ma,ret+a);
		}
		for(i=1;i<=N;i++) {
			if(P[i-1].second==0) {
				tot+=A;
				C[0]--;
			}
			else {
				tot+=B;
				C[1]--;
			}
			if(tot<P[i].first) {
				int lef=P[i].first-1-tot;
				int ret=i;
				int a=min(C[0],lef/A);
				ret+=a;
				lef-=a*A;
				a=min(C[1],lef/B);
				ma=max(ma,ret+a);
			}
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}