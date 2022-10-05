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

int T;
int N;

vector<int> E[1<<16];
int mask[1<<16];
int rev[1<<16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,1<<N) {
			E[i].clear();
			mask[i]=rev[i]=-1;
		}
		FOR(i,N*(1<<(N-1))) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		mask[0]=rev[0]=0;
		FOR(i,E[0].size()) {
			mask[E[0][i]]=1<<i;
			rev[1<<i]=E[0][i];
		}
		for(int tm=0;tm<1<<N;tm++) if(__builtin_popcount(tm)>=2) {
			x=y=-1;
			FOR(i,N) if(tm&(1<<i)) {
				if(x==-1) x=tm^(1<<i);
				else y=tm^(1<<i);
			}
			int vx=rev[x];
			int vy=rev[y];
			set<int> S,S2;
			FORR(e,E[vx]) if(mask[e]==-1) S.insert(e);
			FORR(e,E[vy]) if(mask[e]==-1&&S.count(e)) S2.insert(e);
			assert(S2.size()==1);
			k=*S2.begin();
			mask[k]=tm;
			rev[tm]=k;
		}
		
		FOR(i,1<<N) cout<<rev[i]<<" ";
		cout<<endl;
		if((N&(N-1))==0) {
			FOR(i,1<<N) {
				x=0;
				FOR(j,N) if(mask[i]&(1<<j)) x^=j;
				cout<<x<<" ";
			}
			cout<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}