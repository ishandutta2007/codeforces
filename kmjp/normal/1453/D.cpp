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
ll K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,ll>> V;
	int cur=1;
	ll v=2;
	while(v<1LL<<60) {
		V.push_back({cur,v});
		cur++;
		v=v*2+2;
	}
	reverse(ALL(V));
	
	cin>>T;
	while(T--) {
		cin>>K;
		if(K%2) {
			cout<<-1<<endl;
		}
		else {
			vector<int> ret;
			FORR(v,V) {
				while(K>=v.second) {
					ret.push_back(1);
					FOR(j,v.first-1) ret.push_back(0);
					K-=v.second;
				}
			}
			cout<<ret.size()<<endl;
			FORR(v,ret) cout<<v<<" ";
			cout<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}