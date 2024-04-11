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

int T,N,D;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>D;
		
		multiset<int> S;
		FOR(i,N) {
			cin>>A[i+1];
			S.insert(A[i+1]-A[i]-1);
		}
		int ret=*S.begin();
		
		FOR(i,N-1) {
			S.erase(S.find(A[i+1]-A[i]-1));
			S.erase(S.find(A[i+2]-A[i+1]-1));
			S.insert(A[i+2]-A[i]-1);
			
			ret=max(ret,min({*S.begin(),max((*S.rbegin()-1)/2,D-A[N]-1)}));
			
			S.insert(A[i+1]-A[i]-1);
			S.insert(A[i+2]-A[i+1]-1);
			S.erase(S.find(A[i+2]-A[i]-1));
		}
		S.erase(S.find(A[N]-A[N-1]-1));
		ret=max(ret,min({*S.begin(),max((*S.rbegin()-1)/2,D-A[N-1]-1)}));
		
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}