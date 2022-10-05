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

int t;
int H,C,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&H,&C,&T);
		
		if(2*T<=H+C) {
			_P("2\n");
			continue;
		}
		
		double dif=H-T;
		int ret=0;
		
		for(i=25;i>=0;i--) {
			double a=(1.0*H*((ret+(1<<i))+1)+1.0*C*(ret+(1<<i)))/(2*(ret+(1<<i))+1.0);
			if(a>T) ret+=(1<<i);
		}
		
		for(i=max(1,ret-10);i<=ret+10;i++) {
			double a=(1.0*H*(i+1)+1.0*C*i)/(2*i+1.0);
			if(abs(a-T)<dif) {
				dif=abs(a-T);
				ret=i;
			}
		}
		_P("%d\n",ret*2+1);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}