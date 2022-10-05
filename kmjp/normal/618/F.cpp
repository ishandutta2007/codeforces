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
int A[1010100];
int B[1010100];
int T[1010100];
ll AS[1010100];
ll BS[1010100];
int bask[1010100];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], AS[i+1]=AS[i]+A[i];
	FOR(i,N) cin>>B[i], BS[i+1]=BS[i]+B[i];
	
	MINUS(bask);
	bask[0]=0;
	y=0;
	FOR(i,N) {
		while(y<N&&BS[y+1]<=AS[i+1]) y++;
		T[i]=y;
		int dif=AS[i+1]-BS[y];
		
		if(bask[dif]==-1) bask[dif]=i+1;
		else {
			_P("%d\n",i-(bask[dif]-1));
			for(x=bask[dif];x<=i;x++) _P("%d ",x+1);
			_P("\n");
			_P("%d\n",y-T[bask[dif]-1]);
			for(x=T[bask[dif]-1];x<y;x++) _P("%d ",x+1);
			_P("\n");
			return;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}