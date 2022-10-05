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

int T,N,C,Q;
string S;

ll P[55],len[55],st[55],en[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C>>Q>>S;
		P[0]=0;
		len[0]=N;
		ll cur=N;
		for(i=1;i<=C;i++) {
			ll a,b;
			cin>>a>>b;
			st[i]=a-1;
			en[i]=b;
			len[i]=en[i]-st[i];
			P[i]=cur;
			cur+=len[i];
			cur=min(cur,3LL<<60);
		}
		P[C+1]=cur;
		while(Q--) {
			ll K;
			cin>>K;
			K--;
			while(K>=len[0]) {
				FOR(i,C+2) if(P[i]>K) break;
				i--;
				K=st[i]+K-P[i];
			}
			cout<<S[K]<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}