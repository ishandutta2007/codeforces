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

int T,N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		FOR(i,N) {
			cin>>x;
			M[x]++;
		}
		vector<ll> S={0};
		FORR2(a,b,M) S.push_back(S.back()+b);
		ll ret=1LL<<30;
		FOR(i,S.size()) {
			ll a=S[i];
			ll b=1;
			while(b<a) b*=2;
			ll need=b-a;
			FOR(j,20) {
				ll ne=a+(1<<j);
				x=lower_bound(S.begin(),S.end(),ne+1)-S.begin()-1;
				
				ll c=S[x]-S[i];
				ll d=S.back()-S[x];
				ll e=1,f=1;
				while(e<c) e*=2;
				while(f<d) f*=2;
				ret=min(ret,need+e-c+f-d);
			}
			
			ll g=S.back()-a;
			ll h=1;
			while(h<g) h*=2;
			ret=min(ret,need+h-g+1);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}