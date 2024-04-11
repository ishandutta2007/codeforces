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
int H[404040];
int L[404040];
vector<pair<int,int>> E[404040];
int R[404040];
int ma[404040];
int step[404040];
int ok[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> LIS(N+1,1<<30);
	int MAL=0;
	LIS[0]=0;
	FOR(i,N) {
		cin>>H[i];
		L[i] = lower_bound(LIS.begin(),LIS.end(),H[i]) - LIS.begin();
		LIS[L[i]] = H[i];
		MAL=max(MAL,L[i]);
	}
	for(i=N-1;i>=0;i--) {
		if(L[i]==MAL || ma[L[i]+1]>H[i]) {
			step[L[i]]++;
			ok[i]=1;
			ma[L[i]]=max(ma[L[i]],H[i]);
		}
	}
	
	FOR(i,M) cin>>x>>y, E[x-1].push_back({y,i});
	
	LIS=vector<int>(N+1,1<<30);
	LIS[0]=0;
	FOR(i,N) {
		FORR(r,E[i]) R[r.second]=lower_bound(LIS.begin(),LIS.end(),r.first) - LIS.begin();
		LIS[L[i]] = H[i];
	}
	LIS=vector<int>(N+1,1<<30);
	LIS[0]=-1<<30;
	for(i=N-1;i>=0;i--) {
		FORR(r,E[i]) R[r.second]+=lower_bound(LIS.begin(),LIS.end(),-r.first) - LIS.begin()-1;
		FORR(r,E[i]) R[r.second]=max(R[r.second],MAL-(ok[i]&&step[L[i]]==1));
		x=lower_bound(LIS.begin(),LIS.end(),-H[i]) - LIS.begin();
		LIS[x]=-H[i];
	}
	
	FOR(i,M) _P("%d\n",R[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}