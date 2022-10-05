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
int P[200][5];
int num[5];
int D[5];
int p6[10];
int can[5005][6][7];

int cat(int p,int q) {
	if(p*32<=q) return 5;
	if(p*16<=q) return 4;
	if(p*8<=q) return 3;
	if(p*4<=q) return 2;
	if(p*2<=q) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(x,5) {
			cin>>P[i][x];
			if(P[i][x]>=0) {
				P[i][x]=500-2*P[i][x];
				num[x]++;
			}
		}
	}
	
	for(i=N;i<=5000;i++) {
		FOR(x,5) {
			if(P[0][x]>=0) {
				FOR(y,i-N+1) can[i][x][cat(num[x]+y,i)]=1;
			}
			else {
				can[i][x][cat(num[x],i)]=1;
			}
		}
	}
	
	
	p6[0]=1;
	FOR(i,6) p6[i+1]=p6[i]*6;
	
	int ret=1<<30;
	FOR(i,p6[5]) {
		int A=0,B=0;
		FOR(x,5) {
			D[x]=i/p6[x]%6;
			if(P[0][x]>=0) A+=(D[x]+1)*P[0][x];
			if(P[1][x]>=0) B+=(D[x]+1)*P[1][x];
		}
		if(A<=B) continue;
		
		for(y=N;y<=5000;y++) {
			int ok=1;
			FOR(x,5) ok &= can[y][x][D[x]];
			if(ok) break;
		}
		
		if(y<=5000) ret=min(ret,y-N);
		
	}
	
	if(ret==1<<30) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}