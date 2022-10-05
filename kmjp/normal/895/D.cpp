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

string A,B;
int N;
ll fact[1010100];
ll rev[1010100];
ll mo=1000000007;


ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(string S,string T) {
	int cnt[26]={};
	ll q=1;
	FORR(c,T) q=q*(++cnt[c])%mo;
	q=modpow(q,mo-2);
	ll ret=0;
	
	int left=S.size();
	FORR(c,S) {
		left--;
		for(int i=0;i<c;i++) if(cnt[i]) {
			(ret+=fact[left]*q%mo*cnt[i])%=mo;
		}
		if(cnt[c]==0) break;
		(q*=cnt[c])%=mo;
		cnt[c]--;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	N=A.size();
	FORR(c,A) c-='a';
	FORR(c,B) c-='a';
	
	fact[0]=rev[0]=1;
	for(i=1;i<=1010000;i++) {
		fact[i]=fact[i-1]*i%mo;
		rev[i]=modpow(i,mo-2);
	}
	
	
	cout<<(hoge(B,A)-hoge(A,A)-1+mo*2)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}