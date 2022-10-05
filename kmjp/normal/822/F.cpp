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

int N;
vector<pair<int,int>> E[101];
int X[101],Y[101];
double pos[101];


void dfs(int cur,int pre,double ar) {
	int num=E[cur].size();
	int i;
	FOR(i,num) if(E[cur][i].first!=pre) {
		ar+=2.0/num;
		int x=E[cur][i].second;
		pos[x]=2-ar;
		if(Y[x]==cur) pos[x]+=1;
		while(pos[x]>=2) pos[x]-=2;
		while(pos[x]<0) pos[x]+=2;
		dfs(E[cur][i].first,cur,ar+1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>X[i]>>Y[i];
		X[i]--;
		Y[i]--;
		E[X[i]].push_back({Y[i],i});
		E[Y[i]].push_back({X[i],i});
	}
	
	int num=E[0].size();
	FOR(i,num) {
		double p=i*2.0/num;
		x = E[0][i].second;
		pos[x]=p+(Y[x]==0);
		while(pos[x]>=2) pos[x]-=2;
		while(pos[x]<0) pos[x]+=2;
		
		double nex=1-p;
		if(nex<0) nex+=2;
		dfs(E[0][i].first,0,nex);
		
	}
	
	
	_P("%d\n",N-1);
	FOR(i,N-1) {
		X[i]++;
		Y[i]++;
		if(pos[i]<1) _P("%d %d %d %d %.12lf\n",1,i+1,X[i],Y[i],pos[i]);
		else _P("%d %d %d %d %.12lf\n",1,i+1,Y[i],X[i],pos[i]-1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}