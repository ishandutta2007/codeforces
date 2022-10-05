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
int W,H;
int L[101010],R[101010],U[101010],D[101010];
int X1[101010],X2[101010],Y1[101010],Y2[101010];
int CL,CR,CU,CD;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&W,&H);
	FOR(i,N) {
		scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
		L[min(X1[i],X2[i])]++;
		R[max(X1[i],X2[i])]++;
		U[min(Y1[i],Y2[i])]++;
		D[max(Y1[i],Y2[i])]++;
	}
	scanf("%d%d%d%d",&CL,&CR,&CU,&CD);
	FOR(i,101000) L[i+1]+=L[i], U[i+1]+=U[i];
	for(i=101000;i>=0;i--) R[i]+=R[i+1], D[i]+=D[i+1];
	
	FOR(i,N) {
		int MLR=X1[i]!=X2[i];
		int MUD=Y1[i]!=Y2[i];
		
		if(L[max(X1[i],X2[i])-1]==CL+MLR && R[min(X1[i],X2[i])+1]==CR+MLR) {
			if(U[max(Y1[i],Y2[i])-1]==CU+MUD && D[min(Y1[i],Y2[i])+1]==CD+MUD) {
				cout<<i+1<<endl;
				return;
			}
		}
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}