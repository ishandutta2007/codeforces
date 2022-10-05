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

string S;
int N;
ll mo=998244353;
int X,Y,ma;

ll dp[102][2][10][10][16][16];

ll hoge(int d,int mor,int c1,int c2,int m1,int m2) {
	if(d==N) {
		
		if(mor==0 && c1==0 && c2==0 && (m1&m2)) return 1;
		return 0;
	}
	ll& ret=dp[d][mor][c1][c2][m1][m2];
	if(ret>=0) return ret;
	ret=0;
	
	int a;
	FOR(a,10) {
		int p=a*X+c1;
		int q=a*Y+c2;
		
		int mo2=mor;
		if(q%10>S[d]) mo2=1;
		if(q%10<S[d]) mo2=0;
		
		int nm1=m1;
		int nm2=m2;
		if(p%10>0 && p%10%X==0 && p%10/X<=ma) nm1 |= 1<<(p%10/X-1);
		if(q%10>0 && q%10%Y==0 && q%10/Y<=ma) nm2 |= 1<<(q%10/Y-1);
		ret+=hoge(d+1,mo2,p/10,q/10,nm1,nm2)%mo;
	}
	ret%=mo;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	ll ret=0;
	// add 1/1
	FORR(c,S) {
		c-='0';
		ret=(ret*10+c)%mo;
	}
	reverse(ALL(S));
	
	
	for(X=1;X<=9;X++) {
		for(Y=X+1;Y<=9;Y++) {
			ma=9/Y;
			if(__gcd(X,Y)==1) {
				MINUS(dp);
				ret+=2*hoge(0,0,0,0,0,0);
			}
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}