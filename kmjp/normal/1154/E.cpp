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

int N,K;
set<pair<int,int>> A,B;
int R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		A.insert({x,i});
		B.insert({i,x});
	}
	
	FOR(i,N) if(A.size()) {
		x=A.rbegin()->second;
		R[x]=i%2;
		FOR(j,K) {
			auto it=B.lower_bound({x+1,0});
			if(it==B.end()) break;
			R[it->first]=i%2;
			A.erase({it->second,it->first});
			B.erase(it);
		}
		FOR(j,K) {
			auto it=B.lower_bound({x,0});
			if(it==B.begin()) break;
			it--;
			R[it->first]=i%2;
			A.erase({it->second,it->first});
			B.erase(it);
		}
		auto it=B.lower_bound({x,0});
		A.erase({it->second,it->first});
		B.erase(it);
	}
	
	FOR(i,N) cout<<R[i]+1;
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}