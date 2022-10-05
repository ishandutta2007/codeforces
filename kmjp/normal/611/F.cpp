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

int N,H,W;
string S;
ll mo=1000000007;
ll ret;
ll relx[505050],rely[505050];
ll difx,dify;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H>>W;
	cin>>S;
	
	queue<ll> V;
	FOR(i,N) V.push(i);
	
	int L=0,T=0,R=W-1,B=H-1;
	int ML=0,MR=0,MT=0,MB=0;
	
	ll X=0, Y=0;
	while(V.size() && L<=R && T<=B) {
		ll k=V.front();
		V.pop();
		
		if(k<N) {
			if(S[k%N]=='U') Y--;
			if(S[k%N]=='D') Y++;
			if(S[k%N]=='L') X--;
			if(S[k%N]=='R') X++;
			relx[k]=X, rely[k]=Y;
			if(k==N-1) difx=X,dify=Y;
		}
		else {
			X = difx*(k/N)+relx[k%N];
			Y = dify*(k/N)+rely[k%N];
		}
		int num=0;
		if(X<ML) ML--, L++, num = B-T+1;
		if(X>MR) MR++, R--, num = B-T+1;
		if(Y<MT) MT--, T++, num = R-L+1;
		if(Y>MB) MB++, B--, num = R-L+1;
		if(num) {
			(ret += (k+1)%mo*num)%=mo;
			V.push(k+N);
		}
	}
	
	if(L<=R && T<=B) return _P("-1\n");
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}