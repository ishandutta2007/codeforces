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

int T,N;
int B[505050];
ll L[505050],R[505050];
vector<int> ev[505050];
int P[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) ev[i+1].clear();
		FOR(i,N) {
			cin>>x;
			L[i]=(i+1)/(x+1)+1;
			R[i]=(x==0?N:(i+1)/x);
			L[i]=max(1LL,min(L[i],(ll)N));
			R[i]=max(1LL,min(R[i],(ll)N));
			ev[L[i]].push_back(i);
		}
		set<pair<int,int>> S;
		for(i=1;i<=N;i++) {
			FORR(e,ev[i]) S.insert({R[e],e});
			assert(S.size());
			auto p=*S.begin();
			S.erase(S.begin());
			P[p.second]=i;
		}
		FOR(i,N) cout<<P[i]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}