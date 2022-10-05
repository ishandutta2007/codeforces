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


int K;
ll A[55];
ll H;
const ll mo=998244353;
int ret[32];
unordered_map<int,pair<ll,ll>> memo[6][33];

void dfs(int level,int cur,int h) {
	if(level==0) return;
	auto v=memo[level][cur][h];
	int x=v.first>>32;
	int h1=v.first%(1LL<<30);
	int y=v.second>>32;
	int h2=v.second%(1LL<<30);
	
	if(ret[x]==0) ret[x]=1+(1<<(K-level));
	if(ret[y]==0) ret[y]=1+(1<<(K-level));
	
	dfs(level-1,x,h1);
	dfs(level-1,y,h2);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>A[1]>>H;
	A[0]=1;
	for(i=2;i<=50;i++) A[i]=A[i-1]*A[1]%mo;
	
	FOR(i,1<<K) {
		memo[0][i][0]={};
	}
	FOR(i,K) {
		FOR(y,1<<K) FOR(x,1<<K) {
			if((y>>(i+1)!=x>>(i+1))) continue;
			if((y>>i)==(x>>i)) continue;
			
			FORR2(h1,v,memo[i][x]) {
				FORR2(h2,v2,memo[i][y]) {
					ll h=h1+h2+(y+1)*A[(1<<(K-i-1))+1];
					pair<ll,ll> V={((1LL*x)<<32)+h1,((1LL*y)<<32)+h2};
					memo[i+1][x][h%mo]=V;
				}
			}
		}
	}
	FOR(i,1<<K) {
		ll h=(H+mo-(i+1)*A[1]%mo)%mo;
		
		if(memo[K][i].count(h)) {
			ret[i]=1;
			dfs(K,i,h);
			FOR(j,1<<K) cout<<ret[j]<<" ";
			cout<<endl;
			return;
			
		}
		
		
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}