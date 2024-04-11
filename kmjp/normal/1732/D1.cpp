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

int Q;
ll X;
set<ll> S,del;
map<ll,ll> ma,memo;
map<ll,set<ll>> big;
const int DI=100;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S.insert(0);
	cin>>Q;
	while(Q--) {
		cin>>s>>X;
		if(s=="+") {
			S.insert(X);
			if(del.count(X)) {
				FORR2(a,b,big) if(X%a==0) big[a].erase(X);
				del.erase(X);
			}
		}
		else if(s=="-") {
			S.erase(X);
			del.insert(X);
			FORR2(a,b,big) if(X%a==0) big[a].insert(X);
		}
		else {
			ll cur=memo[X];
			
			if(cur/X>=DI) {
				if(big[X].size()&&*big[X].begin()<=cur) {
					cout<<*big[X].begin()<<endl;
					continue;
				}
				else {
					while(S.count(cur)) cur+=X;
					memo[X]=cur;
				}
			}
			else {
				cur=0;
				while(S.count(cur)) cur+=X;
				memo[X]=cur;
				if(cur/X>=DI) {
					big[X].clear();
				}
			}
			cout<<cur<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}