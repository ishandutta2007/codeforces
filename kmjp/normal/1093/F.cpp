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

int N,K,L;
int A;
ll S[101010];
ll pat[101010][101];
ll sub[101010][101];
int ML[101010][101];

ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	if(L==1) return _P("0\n");
	
	S[0]=1;
	FOR(i,N) {
		cin>>A;
		
		for(x=1;x<=K;x++) if(A==x || A==-1) {
			pat[i+1][x]=S[i]+(mo-sub[i][x])%mo;
			ML[i+1][x]=min(L-1,ML[i][x]+1);
			
			if(ML[i+1][x]==L-1) sub[i+1][x]=(S[i+1-(L-1)]+mo-pat[i+1-(L-1)][x])%mo;
			(S[i+1]+=pat[i+1][x])%=mo;
		}
	}
	cout<<S[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}