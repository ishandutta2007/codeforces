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

int N[4];
ll V[4][200000];

set<int> NG[4][200000];
set<pair<ll,int>> S[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>N[i];
	FOR(i,4) {
		FOR(j,N[i]) cin>>V[i][j];
	}
	FOR(i,3) {
		cin>>k;
		FOR(j,k) {
			cin>>x>>y;
			NG[i+1][y-1].insert(x-1);
		}
	}
	FOR(i,N[0]) S[0].insert({V[0][i],i});
	for(i=1;i<=3;i++) {
		FOR(j,N[i]) {
			FORR(s,S[i-1]) {
				if(NG[i][j].count(s.second)==0) {
					ll sc=s.first+V[i][j];
					
					S[i].insert({sc,j});
					break;
				}
			}
		}
	}
	
	if(S[3].empty()) {
		cout<<-1<<endl;
	}
	else {
		cout<<S[3].begin()->first<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}