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

int N,Q;
int P[20][303030];
int D[303030];
vector<int> E[303030];
int ma[303030];
int tot[303030];
vector<int> ad[303030];
vector<int> de[303030];
set<int> ok[303030];
int ret[303030];

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

void dfs(int cur) {
	tot[cur]=1;
	FORR(r,E[cur]) {
		D[r]=D[cur]+1;
		dfs(r);
		tot[cur]+=tot[r];
		ma[cur]=max(ma[cur],tot[r]);
	}
}

void dfs2(int cur) {
	int id=-1;
	
	FORR(r,E[cur]) {
		dfs2(r);
		if(id==-1 || ok[r].size()>ok[id].size()) id=r;
	}
	if(id>=0) swap(ok[id],ok[cur]);
	FORR(r,E[cur]) FORR(s,ok[r]) ok[cur].insert(s);
	FORR(r,ad[cur]) ok[cur].insert(r);
	assert(ok[cur].size());
	ret[cur]=*ok[cur].begin();
	//_P("%d : ",cur);
	//FORR(r,ok[cur]) _P("%d",r);
	//_P("\n");
	FORR(r,de[cur]) ok[cur].erase(r);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N-1) {
		scanf("%d",&x);
		x--;
		P[0][i+1]=x;
		E[x].push_back(i+1);
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	FOR(i,N) {
		int tma=tot[i];
		int tmi=max(0,ma[i]*2-tot[i]);
		
		
		int L=-1;
		for(j=19;j>=0;j--) if(L+(1<<j)<=D[i]) {
			int p=getpar(i,L+(1<<j));
			if(tot[p]-tot[i]<tmi) L+=1<<j;
		}
		L++;
		if(L>D[i]) continue;
		int R=D[i]+1;
		for(j=19;j>=0;j--) if(R-(1<<j)>=0) {
			int p=getpar(i,R-(1<<j));
			if(tot[p]-tot[i]>tma) R-=1<<j;
		}
		R--;
		if(R<0) continue;
		if(L>R) continue;
		//_P("%d : %d %d\n",i,getpar(i,L),getpar(i,R));
		ad[getpar(i,L)].push_back(i);
		de[getpar(i,R)].push_back(i);
	}
	
	dfs2(0);
	
	FOR(i,Q) {
		scanf("%d",&x);
		_P("%d\n",ret[x-1]+1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}