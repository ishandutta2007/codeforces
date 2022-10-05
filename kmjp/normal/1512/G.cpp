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

int T,C;

const int prime_max = 10000021;
int divp[prime_max];
int ret[prime_max];
int P[prime_max];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		divp[i]=i;
		if(1LL*i*i>prime_max) continue;
		for(int j=i*i;j>=i&&j<=prime_max;j+=i) divp[j]=i;
	}
	for(i=1;i<=prime_max-5;i++) {
		ret[i]=1<<30;
		P[i]=1;
	}
	
	for(i=1;i<=prime_max-5;i++) {
		x=i;
		ll pat=1;
		while(x>1) {
			y=divp[x];
			pat=pat/P[y];
			P[y]=P[y]*y+1;
			pat=pat*P[y];
			x/=y;
		}
		x=i;
		while(x>1) P[divp[x]]=1, x/=divp[x];
		if(pat<=prime_max) ret[pat]=min(ret[pat],i);
	}
	
	cin>>T;
	while(T--) {
		cin>>C;
		if(ret[C]==1<<30) ret[C]=-1;
		cout<<ret[C]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}