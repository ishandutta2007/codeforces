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
int C[10101][22];
ll p3[22];
map<ll,int> M;
int num[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,21) p3[i+1]=p3[i]*3;
	
	cin>>N>>K;
	FOR(y,N) {
		ll v=0;
		FOR(x,K) {
			cin>>C[y][x];
			v+=p3[x]*C[y][x];
		}
		M[v]=y;
	}
	
	FOR(y,N) FOR(x,N) if(x!=y) {
		ll a=0;
		FOR(i,K) {
			int v=(6-C[y][i]-C[x][i])%3;
			a+=v*p3[i];
		}
		if(M.count(a)) {
			num[y]++;
			num[x]++;
			num[M[a]]++;
		}
	}
	
	ll ret=0;
	FOR(i,N) {
		ll v=num[i]/6;
		ret+=v*(v-1)/2;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}