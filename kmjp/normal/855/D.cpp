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
int P[20][101010],T[101010];
int Q;
int D[101010];
int sp[101010],pa[101010];

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	P[0][N]=N;
	FOR(i,N) {
		cin>>P[0][i]>>T[i];
		P[0][i]--;
		if(P[0][i]==-2) P[0][i]=N;
		
		D[i]=D[P[0][i]]+1;
		
		if(T[i]==0) {
			sp[i]=sp[P[0][i]];
			pa[i]=i;
		}
		else {
			pa[i]=pa[P[0][i]];
			sp[i]=i;
		}
	}
	FOR(i,19) FOR(x,N+1) P[i+1][x]=P[i][P[i][x]];
	
	cin>>Q;
	while(Q--) {
		cin>>i>>x>>y;
		x--,y--;
		if(x==y) {
			cout<<"NO"<<endl;
			continue;
		}
		
		int l=lca(x,y);
		if(l==N) {
			cout<<"NO"<<endl;
			continue;
		}
		if(i==1) {
			if(D[x]>=D[y] || l!=x || sp[y]>l) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
		else {
			if(l==y) cout<<"NO"<<endl;
			else if(sp[x]<=l && pa[y]<=l) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}