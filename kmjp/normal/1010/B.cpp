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

int M,N;

int ret[31];

int ask(int v) {
	printf("%d\n",v);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	assert(a!=-2);
	
	if(a==0) exit(0);
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N;
	FOR(i,N) ret[i]=ask(1);
	
	int L=1,R=M+1;
	int cnt=0;
	while(R>L+1) {
		x=(L+R)/2;
		
		y=ask(x)*ret[cnt];
		if(y==-1) R=x;
		else L=x+1;
		cnt=(cnt+1)%N;
	}
	
	ask(L);
	
	
}


int main(int argc,char** argv){
	solve(); return 0;
}