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
int A[303030];
int last[303030];
int ng[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i+1];
			V.push_back({A[i+1],i+1});
		}
		A[N+1]=0;
		FOR(i,N+1) last[i]=ng[i]=0;
		set<int> did;
		did.insert(0);
		did.insert(N+1);
		sort(ALL(V));
		FORR(v,V) {
			x=v.second;
			auto it=did.lower_bound(x);
			int ma=*it-*prev(it)-1;
			last[A[x]]=max(last[A[x]],ma);
			did.insert(x);
		}
		for(i=1;i<=N;i++) {
			int ban=N+1-i;
			if(last[i]>ban) {
				ng[ban+1]++;
				ng[last[i]+1]--;
			}
			if(last[i]<ban) {
				ng[last[i]+1]++;
				ng[ban+1]--;
			}
		}
		for(i=1;i<=N;i++) {
			ng[i]+=ng[i-1];
			if(ng[i]) cout<<0;
			else cout<<1;
		}
		cout<<endl;
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}