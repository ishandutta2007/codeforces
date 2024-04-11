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

const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


int T;
int H,W,SY,SX,TY,TX,P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>SY>>SX>>TY>>TX>>P;
		SY--,SX--,TY--,TX--;
		ll p=P*modpow(100)%mo;
		ll q=(100-P)*modpow(100)%mo;
		ll a=1;
		ll ret=0;
		x=y=1;
		FOR(i,4*(H-1)*(W-1)) {
			if(SY==TY||SX==TX) {
				(ret+=i*a%mo*p)%=mo;
				a=a*q%mo;
			}
			if(SY+y==H||SY+y==-1) y=-y;
			if(SX+x==W||SX+x==-1) x=-x;
			SY+=y;
			SX+=x;
		}
		
		ret=ret*modpow(1+mo-a)%mo;
		ret+=4*(H-1)*(W-1)*a%mo*modpow(1+mo-a)%mo;
		cout<<ret%mo<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}