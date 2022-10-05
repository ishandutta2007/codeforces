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

int K,Q;
int B[2020][2020];
int I[2020][2020];
int L[2020];
int X[2020][2020];
int Y[2020][2020];
int W[2020][2020];
ll S[2020][2020];
int off[2020];
char C[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&x,&y,&K);
	MINUS(B);
	FOR(i,K) {
		scanf("%d",&L[i]);
		FOR(j,L[i]) {
			scanf("%d%d%d",&X[i][j],&Y[i][j],&W[i][j]);
			B[Y[i][j]][X[i][j]]=i;
			I[Y[i][j]][X[i][j]]=j;
			S[i][j+1]=S[i][j]+W[i][j];
		}
	}
	scanf("%d",&Q);
	while(Q--) {
		int x1,x2,y1,y2;
		scanf("%s %d",C,&x1);
		if(C[0]=='S') off[x1-1] ^= 1;
		else {
			scanf("%d%d%d",&y1,&x2,&y2);
			ll tot=0;
			
			FOR(i,K) if(off[i]==0) {
				if(X[i][L[i]-1]>=x1 && X[i][L[i]-1]<=x2 && 
				   Y[i][L[i]-1]>=y1 && Y[i][L[i]-1]<=y2) tot += S[i][L[i]];
			}
			for(x=x1;x<=x2;x++) {
				if(B[y1][x]>=0 && off[B[y1][x]]==0 && B[y1-1][x]==B[y1][x]) {
					if(I[y1-1][x]==I[y1][x]-1) tot -= S[B[y1][x]][I[y1][x]];
					if(I[y1-1][x]==I[y1][x]+1) tot += S[B[y1][x]][I[y1][x]+1];
				}
				if(B[y2][x]>=0 && off[B[y2][x]]==0 && B[y2+1][x]==B[y2][x]) {
					if(I[y2+1][x]==I[y2][x]-1) tot -= S[B[y2][x]][I[y2][x]];
					if(I[y2+1][x]==I[y2][x]+1) tot += S[B[y2][x]][I[y2][x]+1];
				}
			}
			for(y=y1;y<=y2;y++) {
				if(B[y][x1]>=0 && off[B[y][x1]]==0 && B[y][x1-1]==B[y][x1]) {
					if(I[y][x1-1]==I[y][x1]-1) tot -= S[B[y][x1]][I[y][x1]];
					if(I[y][x1-1]==I[y][x1]+1) tot += S[B[y][x1]][I[y][x1]+1];
				}
				if(B[y][x2]>=0 && off[B[y][x2]]==0 && B[y][x2+1]==B[y][x2]) {
					if(I[y][x2+1]==I[y][x2]-1) tot -= S[B[y][x2]][I[y][x2]];
					if(I[y][x2+1]==I[y][x2]+1) tot += S[B[y][x2]][I[y][x2]+1];
				}
			}
			
			cout<<tot<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}