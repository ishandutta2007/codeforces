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

ll L,R,K;
ll p10[20];
ll mo=998244353;

ll S[20][2][1<<10];
ll num[20][2][1<<10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R>>K;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	ll ret=0;
	
	FOR(i,2) {
		ll N=(i==0)?R:L-1;
		ZERO(S);
		ZERO(num);
		num[19][1][0]=1;
		
		for(j=18;j>=0;j--) {
			for(int mask=0;mask<1<<10;mask++) {
				FOR(x,2) {
					FOR(y,10) {
						if(x&&y>N/p10[j]%10) continue;
						
						int nmask=mask | (1<<y);
						if(mask==0 && y==0) nmask=0;
						int ty=x;
						if(x==1 && y<N/p10[j]%10) ty=0;
						
						(num[j][ty][nmask] += num[j+1][x][mask])%=mo;
						(S[j][ty][nmask] += S[j+1][x][mask]+num[j+1][x][mask]*y%mo*p10[j])%=mo;
						
					}
				}
			}
		}
		for(int mask=0;mask<1<<10;mask++) if(__builtin_popcount(mask)<=K) {
			if(i==0) ret+=S[0][0][mask]+S[0][1][mask];
			else ret-=S[0][0][mask]+S[0][1][mask];
		}
	}
	
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}