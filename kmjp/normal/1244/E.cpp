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
ll K;
map<ll,ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		M[x]++;
	}
	
	while(M.size()>1 && K) {
		if(M.begin()->second<M.rbegin()->second) {
			auto a=*M.begin();
			M.erase(M.begin());
			ll d=M.begin()->first-a.first;
			if(d*a.second<=K) {
				K-=d*a.second;
				M.begin()->second+=a.second;
			}
			else {
				M[a.first+K/a.second]=1;
				K=0;
			}
		}
		else {
			auto a=*M.rbegin();
			M.erase(M.rbegin()->first);
			ll d=a.first-M.rbegin()->first;
			if(d*a.second<=K) {
				K-=d*a.second;
				M.rbegin()->second+=a.second;
			}
			else {
				M[a.first-K/a.second]=1;
				K=0;
			}
		}
	}
	
	if(M.size()==1) {
		cout<<0<<endl;
	}
	else {
		cout<<M.rbegin()->first-M.begin()->first<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}