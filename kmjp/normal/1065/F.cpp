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

int N,K;
vector<int> E[1010101];
int D[1010101];
int RD[1010101];
vector<int> Ds[1010101];

int P[1010101];
int num[1010101];
int ma[1010101];
int del[1010101];

void dfs(int cur) {
	if(cur) D[cur]=D[P[cur]]+1;
	Ds[D[cur]].push_back(cur);
	FORR(e,E[cur]) dfs(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	for(i=1;i<N;i++) {
		scanf("%d",&x);
		x--;
		P[i]=x;
		E[x].push_back(i);
		RD[i]=i;
	}
	dfs(0);
	
	int d;
	FOR(d,N) {
		FORR(e,Ds[d]) if(E[e].empty()) {
			x=e;
			FOR(i,K) {
				if(x==0) break;
				x=P[x];
				if(RD[x]!=x) break;
			}
			RD[e]=x=RD[x];
			x=e;
			FOR(i,K) {
				if(x==0) break;
				x=P[x];
				if(RD[x]==RD[e]) break;
				RD[x]=RD[e];
			}
		}
	}
	int ret=0;
	for(x=N-1;x>=0;x--) FORR(i,Ds[x]) {
		if(E[i].empty()) {
			num[i]++;
			del[RD[i]]++;
			ma[i]=1;
		}
		else {
			FORR(e,E[i]) num[i]+=num[e];
			FORR(e,E[i]) ma[i]=max(ma[i],num[i]-num[e]+ma[e]);
			num[i]-=del[i];
		}
		
		ret=max(ret,ma[i]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}