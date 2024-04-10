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
const ll mo=998244353;
int X[1010101];
int LL[501],RR[501];

ll memo[1201][1201];

ll hoge(int L,int R) {
	if(L+1>=R) return 1;
	if(memo[L][R]>=0) return memo[L][R];
	int M=L;
	int i;
	int ML=L,MR=L;
	for(i=L+1;i<R;i++) {
		if(X[i]<X[M]) M=i, ML=i;
		if(X[i]==X[M]) MR=i;
	}
	
	ll LS=0,RS=0;
	set<int> NG;
	for(i=ML;i>=L;i--) {
		if(i!=LL[X[i]]) NG.insert(X[i]);
		if(i==LL[X[i]]) NG.erase(X[i]);
		if(NG.empty()) LS+=hoge(L,i)*hoge(i,ML)%mo;
	}
	NG.clear();
	for(i=MR;i<R;i++) {
		if(i!=RR[X[i]]) NG.insert(X[i]);
		if(i==RR[X[i]]) NG.erase(X[i]);
		if(NG.empty()) RS+=hoge(MR+1,i+1)*hoge(i+1,R)%mo;
	}
	LS%=mo;
	RS%=mo;
	ll ret=LS*RS%mo;
	int pre=ML;
	for(i=ML;i<=MR;i++) {
		if(X[i]==X[M]) {
			ret=ret*hoge(pre+1,i)%mo;
			pre=i;
		}
	}
	
	return memo[L][R]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	
	cin>>N>>M;
	FOR(i,N) LL[i+1]=M+1;
	FOR(i,M) {
		cin>>X[i];
		if(i&&X[i]==X[i-1]) {
			i--;
			M--;
			continue;
		}
		RR[X[i]]=i;
		LL[X[i]]=min(LL[X[i]],i);
	}
	FOR(i,M) {
		for(y=X[i]+1;y<=N;y++) if(LL[y]<i && RR[y]>i) return _P("0\n");
	}
	
	cout<<hoge(0,M)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}