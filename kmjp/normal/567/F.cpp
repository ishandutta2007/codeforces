#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int X[101],Y[101];
string S[101];
vector<int> V[101];
ll ret;
ll dp[101][101];

int okok(int lo1,int lo2,int hi1,int hi2,int x,int y,string s) {
	int xv=0,yv=0;
	if(hi1<=x && x<=hi2) xv=2;
	else if(x==lo1 || x==lo2) xv=1;
	if(hi1<=y && y<=hi2) yv=2;
	else if(y==lo1 || y==lo2) yv=1;
	
	if(s=="=") return xv == yv;
	if(s=="<") return xv < yv;
	if(s==">") return xv > yv;
	if(s=="<=") return xv <= yv;
	if(s==">=") return xv >= yv;
	return 0;
}

ll dpdp(int L,int R) {
	if(R-L+1==2*N) return 1;
	if(L<0 || R>=2*N) return 0;
	if(dp[L][R]>=0) return dp[L][R];
	ll ret=0;
	
	if(L>=2) {
		int ok=1;
		FORR(r,V[L-1]) ok &= okok(L-2,L-1,L,R,X[r],Y[r],S[r]);
		FORR(r,V[L-2]) ok &= okok(L-2,L-1,L,R,X[r],Y[r],S[r]);
		if(ok) ret += dpdp(L-2,R);
	}
	if(L>=1 && R<=2*N-2) {
		int ok=1;
		FORR(r,V[L-1]) ok &= okok(L-1,R+1,L,R,X[r],Y[r],S[r]);
		FORR(r,V[R+1]) ok &= okok(L-1,R+1,L,R,X[r],Y[r],S[r]);
		if(ok) ret += dpdp(L-1,R+1);
	}
	if(R<=2*N-3) {
		int ok=1;
		FORR(r,V[R+1]) ok &= okok(R+1,R+2,L,R,X[r],Y[r],S[r]);
		FORR(r,V[R+2]) ok &= okok(R+1,R+2,L,R,X[r],Y[r],S[r]);
		if(ok) ret += dpdp(L,R+2);
	}
	return dp[L][R]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>X[i]>>S[i]>>Y[i];
		X[i]--;
		Y[i]--;
		V[X[i]].push_back(i);
		V[Y[i]].push_back(i);
	}
	
	MINUS(dp);
	FOR(i,2*N-1) {
		int ok=1;
		FORR(r,V[i]) ok &= okok(i,i+1,i,i+1,X[r],Y[r],S[r]);
		FORR(r,V[i+1]) ok &= okok(i,i+1,i,i+1,X[r],Y[r],S[r]);
		if(ok) ret+=dpdp(i,i+1);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}