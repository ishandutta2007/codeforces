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

int X,Y;
int LR[101010],UD[101010];
int N;
string S;

ll can(ll step) {
	ll LR2=LR[N]*(step/N)+LR[step%N];
	ll UD2=UD[N]*(step/N)+UD[step%N];
	
	return (abs(X-LR2)+abs(Y-UD2)<=step);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>y;
	cin>>X>>Y;
	X-=x;
	Y-=y;
	cin>>N>>S;
	FOR(i,N) {
		LR[i+1]=LR[i];
		UD[i+1]=UD[i];
		if(S[i]=='U') UD[i+1]++;
		if(S[i]=='D') UD[i+1]--;
		if(S[i]=='L') LR[i+1]--;
		if(S[i]=='R') LR[i+1]++;
	}
	
	ll ret=(1LL<<50)-1;
	if(can(ret)==0) return _P("-1\n");
	for(i=49;i>=0;i--) if(can(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}