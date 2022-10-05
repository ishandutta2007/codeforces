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

int T;
ll L,R;

ll memo[40][2][2];

ll dfs(int d,int Lmore,int Rless) {
	if(d==-1) return Lmore;
	if(memo[d][Lmore][Rless]>=0) return memo[d][Lmore][Rless];
	ll ret=0;
	
	if(Lmore==0 && (L&(1<<d))) {
		// L
		ret+=dfs(d-1,0,Rless || (R&(1<<d)));
	}
	else {
		// 0
		ret+=dfs(d-1,Lmore,Rless || (R&(1<<d)));
		// L
		ret+=dfs(d-1,Lmore || (L&(1<<d))==0,Rless || (R&(1<<d)));
		// R
		if(Rless||(R&(1<<d))) ret+=dfs(d-1,Lmore,Rless);
	}
	
	
	return memo[d][Lmore][Rless]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R;
		
		ll ret=0;
		if(L==0) {
			ret+=2*R+1;
			L++;
		}
		
		if(L<R) {
			L--;
			while(L<R) {
				int msb=0;
				while(1<<(msb+1)<=R) msb++;
				
				if(L+1>=1<<msb) break;
				MINUS(memo);
				ret+=2*dfs(msb-1,0,0);
				R=(1<<msb)-1;
			}
		}
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}