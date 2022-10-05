#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N,Q;
string S,T;
int need[1<<17][19];
const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>Q;
	int unf=0;
	FORR(c,S) if(c=='?') unf++;
	FOR(y,2) {
		FOR(i,N) {
			int mask=0;
			int f=unf;
			FOR(j,N) {
				if(i+j+y>=N||i-j<0) break;
				char a=S[i+j+y];
				char b=S[i-j];
				if(a=='?'&&b=='?') {
					if(j||y) f--;
				}
				else if(a=='?') {
					mask|=1<<(b-'a');
					f--;
				}
				else if(b=='?') {
					mask|=1<<(a-'a');
					f--;
				}
				else {
					if(a!=b) break;
				}
				FOR(x,18) (need[mask][x]+=modpow(x,f))%=mo;
			}
		}
	}
	int mask;
	FOR(x,18) {
		FOR(i,17) {
			FOR(mask,1<<17) if(mask&(1<<i)) (need[mask][x]+=need[mask^(1<<i)][x])%=mo;
		}
	}
	while(Q--) {
		cin>>T;
		int mask=0;
		x=T.size();
		FORR(c,T) mask|=1<<(c-'a');
		cout<<need[mask][x]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}