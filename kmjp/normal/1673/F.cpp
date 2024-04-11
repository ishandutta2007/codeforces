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


int N,K;

int R[33],RS[33];
int C[33],CS[33];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=32;i++) {
		x=i;
		R[i]=1;
		while(x%2==0) x/=2,R[i]*=4;
		RS[i]=RS[i-1]^R[i];
		C[i]=R[i]*2;
		CS[i]=RS[i]*2;
	}
	
		
	
	
	cin>>N>>K;

	FOR(y,N) {
		FOR(x,N-1) cout<<R[x+1]<<" ";
		cout<<endl;
	}
	FOR(y,N-1) {
		FOR(x,N) cout<<C[y+1]<<" ";
		cout<<endl;
	}
	
	int pre=0;
	while(K--) {
		cin>>k;
		FOR(y,N) FOR(x,N) {
			if((RS[x]|CS[y])==(pre^k)) cout<<y+1<<" "<<x+1<<endl;
		}
		pre^=k;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}