#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A,B,M;
int X[101010],Y[101010];
int used[2010][2010];
int in[2010];
int C;
int ret[2020][2020];

void gofree(int v,int tofree,int okc) {
	int tar=used[v][tofree];
	if(tar!=-1) {
		used[v][tofree]=-1;
		used[tar][tofree]=-1;
		gofree(tar,okc,tofree);
		used[v][okc]=tar;
		used[tar][okc]=v;
		ret[min(v,tar)][max(v,tar)]=okc;
	}
	return;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(used);
	
	cin>>A>>B>>M;
	FOR(i,M) {
		cin>>X[i]>>Y[i];
		X[i]--, Y[i]--;
		Y[i]+=A;
		C=max(C,++in[X[i]]);
		C=max(C,++in[Y[i]]);
		
		int c1=-1,c2=-1;
		FOR(y,C) {
			if(c1==-1 && used[X[i]][y]>=0 && used[Y[i]][y]==-1) c1=y;
			if(c2==-1 && used[X[i]][y]==-1 && used[Y[i]][y]>=0) c2=y;
			if(used[X[i]][y]==-1 && used[Y[i]][y]==-1) break;
		}
		
		if(y>=C) {
			gofree(Y[i],c2,c1);
			y=c2;
		}
		ret[X[i]][Y[i]]=y;
		used[X[i]][y]=Y[i];
		used[Y[i]][y]=X[i];
	}
	
	cout<<C<<endl;
	FOR(i,M) cout<<(ret[X[i]][Y[i]]+1)<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}