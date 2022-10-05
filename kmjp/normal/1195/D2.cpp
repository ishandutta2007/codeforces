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
vector<ll> V[12];
ll p10[12];
ll mo=998244353;

pair<vector<ll>,vector<ll>> hoge(int a,int b) {
	vector<ll> A,B;
	ll p=1;
	while(a&&b) {
		B.push_back(p);
		p=p*10%mo;
		A.push_back(p);
		p=p*10%mo;
		a--,b--;
	}
	
	while(a--) {
		A.push_back(p);
		p=p*10%mo;
	}
	while(b--) {
		B.push_back(p);
		p=p*10%mo;
	}
	return {A,B};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,11) p10[i+1]=p10[i]*10;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		
		FOR(j,11) if(x<p10[j]) break;
		V[j].push_back(x);
	}
	
	ll ret=0;
	for(i=1;i<=10;i++) {
		for(j=1;j<=10;j++) {
			auto P=hoge(i,j);
			
			FORR(v,V[i]) {
				ll a=v;
				FORR(p,P.first) {
					ret+=a%10*p%mo*V[j].size()%mo;
					a/=10;
				}
			}
			FORR(v,V[j]) {
				ll a=v;
				FORR(p,P.second) {
					ret+=a%10*p%mo*V[i].size()%mo;
					a/=10;
				}
			}
			
		}
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}