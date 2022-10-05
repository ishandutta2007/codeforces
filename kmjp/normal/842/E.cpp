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
int P[21][300005],D[300005];

int X[303030],Y[303030],dia[303030];
int ret[303030];

int dist(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]];  // dist
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>P[0][i+1];
		P[0][i+1]--;
		D[i+1]=D[P[0][i+1]]+1;
	}
	FOR(i,19) FOR(x,M+1) P[i+1][x]=P[i][P[i][x]];
	
	X[1]=0;
	Y[1]=dia[1]=1;
	for(i=2;i<=M;i++) {
		X[i]=X[i-1];
		Y[i]=Y[i-1];
		dia[i]=dia[i-1];
		
		if(dist(X[i],i)>dia[i-1]) {
			dia[i]++;
			Y[i]=i;
		}
		else if(dist(Y[i],i)>dia[i-1]) {
			dia[i]++;
			X[i]=i;
		}
	}
	
	FOR(i,M+1) {
		ret[i]++;
		x=i-1;
		for(j=20;j>=0;j--) {
			int tmp=x+(1<<j);
			if(tmp>M) continue;
			if(max(dist(X[tmp],i),dist(Y[tmp],i))==dia[tmp]) x=tmp;
		}
		ret[x+1]--;
	}
	for(i=1;i<=M;i++) {
		ret[i]+=ret[i-1];
		_P("%d\n",ret[i]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}