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

int N,M,Q;
int A[101010],B[101010],C[101010];
vector<pair<int,int>> E[101010];

ll ret[101010];
ll add[101010];
queue<int> ev[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&Q);
	FOR(i,M) {
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
		A[i]--;
		B[i]--;
		E[A[i]].push_back({B[i],C[i]});
		C[i]=E[A[i]].size()-1;
	}
	
	FOR(i,N) ret[i]=add[i]=1LL<<60;
	ret[0]=0;
	priority_queue<pair<ll,int>> PQ;
	PQ.push({0,0});
	while(PQ.size()) {
		ll co=-PQ.top().first;
		int cur=PQ.top().second;
		PQ.pop();
		if(ret[cur]!=co) continue;
		FORR(e,E[cur]) if(ret[e.first]>co+e.second) {
			ret[e.first]=co+e.second;
			PQ.push({-ret[e.first],e.first});
		}
	}
	
	
	while(Q--) {
		scanf("%d%d",&x,&y);
		if(x==1) {
			cout<<((ret[y-1]>=1LL<<60)?-1:ret[y-1])<<endl;
		}
		else {
			
			FOR(i,y) scanf("%d",&x), E[A[x-1]][C[x-1]].second++;
			add[0]=0;
			ev[0].push(0);
			FOR(i,y+1) {
				while(ev[i].size()) {
					int cur=ev[i].front();
					ev[i].pop();
					if(add[cur]!=i) continue;
					FORR(e,E[cur]) {
						ll d = ret[cur]-ret[e.first]+(add[cur]+e.second);
						if(d<=y && add[e.first]>d) {
							add[e.first]=d;
							ev[add[e.first]].push(e.first);
						}
					}
				}
			}
			FOR(i,N) if(add[i]!=1LL<<60) {
				ret[i]+=add[i];
				add[i]=1LL<<60; 
			}
		}
		
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}