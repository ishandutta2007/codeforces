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

int N,M;
int cnt[1<<20];
int sum[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) scanf("%d",&x), cnt[x]=1;
	FOR(i,(1<<20)-1) sum[i+1]=sum[i]+(cnt[i]^1);
	
	int tot=0;
	FOR(i,M) {
		scanf("%d",&x);
		tot^=x;
		
		int ret=0;
		int tota=0;
		for(j=19;j>=0;j--) {
			int bj=1<<j;
			
			if(tot&bj) {
				if(sum[(ret^tota)+2*bj]-sum[(ret^tota)+bj]==0) ret ^= bj;
				tota |= bj;
			}
			else {
				if(sum[(ret^tota)+bj]-sum[(ret^tota)]==0) ret ^= bj;
			}
		}
		_P("%d\n",ret);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}