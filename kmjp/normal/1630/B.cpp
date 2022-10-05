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


int T,N,K;
int A[202020];
int num[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N+1) num[i]=0;
		FOR(i,N) {
			cin>>A[i];
			num[A[i]]++;
		}
		int mi=1<<20;
		for(i=1;i<=N;i++) {
			num[i]+=num[i-1];
		}
		for(int L=1,R=0;L<=N;L++) {
			while(R<=N&&2*(num[R]-num[L-1])<N+K) R++;
			if(R>N) break;
			if(R-L<mi) {
				mi=R-L;
				x=L,y=R;
			}
		}
		vector<pair<int,int>> V;
		FOR(i,N) {
			j=(x<=A[i]&&A[i]<=y);
			if(V.size()&&V.back().first!=j) V.pop_back();
			else V.push_back({j,i});
		}
		int pre=1;
		vector<pair<int,int>> ret;
		FOR(i,K-1) {
			ret.push_back({pre,V[i].second+1});
			pre=V[i].second+2;
		}
		ret.push_back({pre,N});
		
		cout<<x<<" "<<y<<endl;
		FORR2(a,b,ret) cout<<a<<" "<<b<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}