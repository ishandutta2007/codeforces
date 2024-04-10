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


int M,K;
ll X[1010][1010];
ll S[1010];
ll S2[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>K;
	FOR(y,K) {
		FOR(x,M) {
			cin>>X[y][x];
			S[y]+=X[y][x];
			S2[y]+=X[y][x]*X[y][x];
		}
	}
	map<ll,int> D;
	FOR(y,K-1) D[S[y+1]-S[y]]++;
	ll SV;
	FORR2(a,b,D) if(b>=2) SV=a;
	int inval=-1;
	for(i=1;i<K-1;i++) {
		if(S[i]-S[i-1]!=SV&&S[i+1]-S[i]!=SV) inval=i;
	}
	
	ll SV2=0;
	FOR(i,K-2) {
		if(inval<i||i+2<inval) {
			SV2=(S2[i+2]+S2[i]-2*S2[i+1])/2;
			break;
		}
	}
	
	ll add=(S[inval+1]+S[inval-1]-2*S[inval])/2;
	ll add2=(S2[inval+1]+S2[inval-1]-2*S2[inval])/2-SV2;
	ll sum=add2/add;
	ll ret=(sum+add)/2;
	cout<<inval<<" "<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}