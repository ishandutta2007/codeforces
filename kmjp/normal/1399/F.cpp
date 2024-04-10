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

int T;
int N;
int L[3030],R[3030];

int dp[6060];
vector<pair<int,int>> ev[6060];
int num[6060];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> Xs;
		FOR(i,N) {
			cin>>L[i]>>R[i];
			L[i]=L[i]*2;
			R[i]=R[i]*2+1;
			Xs.push_back(L[i]);
			Xs.push_back(R[i]);
		}
		Xs.push_back(0);
		L[N]=0;
		R[N]=502020;
		Xs.push_back(502020);
		N++;
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(i,Xs.size()+10) ev[i].clear();
		vector<pair<int,int>> cand;
		FOR(i,N) {
			L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
			R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
			cand.push_back({R[i]-L[i],i});
		}
		
		sort(ALL(cand));
		FORR(c,cand) {
			x=c.second;
			ZERO(dp);
			
			int cur=0;
			for(i=L[x];i<=R[x];i++) {
				cur=max(cur,dp[i]);
				FORR(e,ev[i]) {
					dp[e.first]=max(dp[e.first],cur+e.second);
				}
			}
			num[x]=cur+1;
			ev[L[x]].push_back({R[x],num[x]});
		}
		cout<<num[N-1]-1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}