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

int T,N,A[202020];
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		cin>>S;
		multiset<int> R,B;
		FOR(i,N) {
			if(S[i]=='R') {
				R.insert(A[i]);
			}
			else {
				B.insert(A[i]);
			}
		}
		for(i=1;i<=N;i++) {
			if(B.size()) {
				if(*B.begin()>=i) {
					B.erase(B.begin());
				}
				else {
					break;
				}
			}
			else if(R.size()) {
				if(*R.begin()<=i) {
					R.erase(R.begin());
				}
				else {
					break;
				}
			}
		}
		if(i>N) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}