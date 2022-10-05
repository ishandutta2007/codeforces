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
ll X[202020],Y[202020];
map<ll,vector<pair<ll,ll>>> M;
ll from[2], to[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		M[max(X[i],Y[i])].push_back({X[i],Y[i]});
	}
	
	pair<ll,ll> PL={0,0},PR={0,0};
	FORR(m,M) {
		pair<ll,ll> L={-1,m.first+1},R={m.first+1,-1};
		FORR(a,m.second) {
			if(a.first>L.first || a.second<L.second) L=a;
			if(a.first<R.first || a.second>R.second) R=a;
		}
		to[0]=to[1]=1LL<<60;
		to[0]=min(to[0],from[0]+abs(PL.first-R.first)+abs(R.first-L.first)+abs(PL.second-R.second)+abs(R.second-L.second));
		to[0]=min(to[0],from[1]+abs(PR.first-R.first)+abs(R.first-L.first)+abs(PR.second-R.second)+abs(R.second-L.second));
		to[1]=min(to[1],from[0]+abs(PL.first-L.first)+abs(R.first-L.first)+abs(PL.second-L.second)+abs(R.second-L.second));
		to[1]=min(to[1],from[1]+abs(PR.first-L.first)+abs(R.first-L.first)+abs(PR.second-L.second)+abs(R.second-L.second));
		PL=L;
		PR=R;
		swap(to,from);
	}
	cout<<min(from[0],from[1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}