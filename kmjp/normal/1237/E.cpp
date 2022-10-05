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

int N;
int TL[(1<<20)+10],TR[(1<<20)+10];
ll memo[1010101][2];
const ll mo=998244353;
ll hoge(int L,int R,int odd) ;

ll hoge2(int L,int odd) {
	if(memo[L][odd]>=0) return memo[L][odd];
	
	ll ret=0;
	for(int i=1;i<=L;i++) if((i&1)==odd) {
		int a=i-1;
		int b=L-i;
		if(max(TR[a],TR[b])-min(TL[a],TL[b])<=1) {
			(ret+=hoge(1,i,odd^1)*hoge(i+1,L+1,odd))%=mo;
		}
	}
	return memo[L][odd]=ret;
}


ll hoge(int L,int R,int odd) {
	if(R-L<=0) return 1;
	odd ^= 1^(L&1);
	return hoge2(R-L,odd);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	/*
	for(i=1;i<=20;i++) TL[(1<<i)-1]++;
	FOR(i,21) TR[(1<<i)]++;
	for(i=2;i<=1<<20;i++) {
		TL[i]+=TL[i-1];
		TR[i]+=TR[i-1];
	}
	MINUS(memo);
	for(i=1;i<=1000000;i++) {
		ll a=hoge(1,i+1,0);
		if(a) cout<<i<<" "<<0<<" "<<a<<endl;
		ll b=hoge(1,i+1,1);
		if(b) cout<<i<<" "<<1<<" "<<b<<endl;
		
	}
	*/
	
	cin>>N;
	x=1;
	set<int> S;
	FOR(i,20) {
		if(x>N) break;
		S.insert(x);
		x++;
		S.insert(x);
		x*=2;
		S.insert(x);
		x++;
		S.insert(x);
		x*=2;
		x--;
		S.insert(x);
	}
	
	cout<<S.count(N)<<endl;
	//cout<<(hoge(1,N+1,0)+hoge(1,N+1,1))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}