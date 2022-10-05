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

int T;
ll X,D;

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

ll issq(ll V) {
	ll a=sqrt(V);
	if(a*a==V) return a;
	if((a-1)*(a-1)==V) return a-1;
	if((a+1)*(a+1)==V) return a+1;
	return 0;
}

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>X>>D;
		
		if(X%(D*D)) {
			cout<<"NO"<<endl;
			continue;
		}
		
		if(isprime(D)) {
			while(X%D==0) X/=D;
			
			if(X==1||isprime(X)) {
				cout<<"NO"<<endl;
			}
			else {
				cout<<"YES"<<endl;
			}
		}
		else {
			X/=D*D;
			
			if(X==1||isprime(X)) {
				cout<<"NO"<<endl;
			}
			else {
				auto M=enumpr(X);
				auto DD=enumpr(D);
				if(M.size()>=2||DD.size()>=2) {
					cout<<"YES"<<endl;
				}
				else if(M.begin()->first!=DD.begin()->first) {
					cout<<"YES"<<endl;
				}
				else if(M.begin()->second==3&&DD.begin()->second==2) {
					cout<<"NO"<<endl;
				}
				else {
					cout<<"YES"<<endl;
				}
				
			}
			
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}