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

int H,W,K;
int R[10101],C[10101],rid[10101],cid[10101];
vector<pair<int,int>> RR[10101];
vector<pair<int,int>> CC[10101];
priority_queue<pair<int,int>> Q;

int dist[10101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	FOR(i,K) {
		cin>>R[i]>>C[i];
		R[i]--;
		C[i]--;
		dist[i]=101010;
		if(R[i]==0 && C[i]==0) {
			dist[i]=0;
			Q.push({0,i});
		}
	}
	
	int mi=101010;
	while(Q.size()) {
		int co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(dist[cur]!=co) continue;
		
		if(R[cur]==H-1&&C[cur]==W-1) mi=min(mi,dist[cur]);
		if(R[cur]>=H-2||C[cur]>=W-2) mi=min(mi,dist[cur]+1);
		
		FOR(i,K) if(i!=cur) {
			if(abs(R[cur]-R[i])+abs(C[cur]-C[i])<=1) {
				if(dist[i]>dist[cur]) {
					dist[i]=dist[cur];
					Q.push({-dist[i],i});
				}
			}
			else if(abs(R[cur]-R[i])<=2 || abs(C[cur]-C[i])<=2) {
				if(dist[i]>dist[cur]+1) {
					dist[i]=dist[cur]+1;
					Q.push({-dist[i],i});
				}
			}
		}
	}
	if(mi==101010) mi=-1;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}