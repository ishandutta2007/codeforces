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

int T,N,A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		vector<ll> C[2];
		FOR(i,N) {
			cin>>x;
			C[A[i]].push_back(x);
		}
		sort(ALL(C[0]));
		sort(ALL(C[1]));
		reverse(ALL(C[0]));
		reverse(ALL(C[1]));
		ll ma=0;
		if(C[0].size()<C[1].size()) swap(C[0],C[1]);
		if(C[0].size()>C[1].size()) {
			FOR(i,C[1].size()) ma+=2*(C[0][i]+C[1][i]);
			FOR(i,C[0].size()) if(i>=C[1].size()) ma+=C[0][i];
		}
		else {
			FOR(i,C[0].size()) ma+=2*(C[0][i]+C[1][i]);
			ma-=min(C[0].back(),C[1].back());
		}
		
		
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}