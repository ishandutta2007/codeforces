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

int N,M;
vector<int> E[3030],F[3030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		E[x-1].push_back(y);
	}
	ll mi=1LL<<60;
	FOR(i,M) sort(ALL(E[i]));
	FOR(i,M) reverse(ALL(E[i]));
	
	for(int len=max(1,(int)E[0].size());len<=N;len++) {
		ll tot=0;
		int num=E[0].size();
		vector<int> left;
		for(i=1;i<M;i++) {
			F[i]=E[i];
			while(F[i].size()>=len) {
				num++;
				tot+=F[i].back();
				F[i].pop_back();
			}
			FORR(f,F[i]) left.push_back(f);
		}
		
		sort(ALL(left));
		FOR(i,len-num) tot+=left[i];
		mi=min(mi,tot);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}