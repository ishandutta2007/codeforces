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

int T,N,M,K;
string A,B;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K>>A>>B;
		x=0;
		sort(ALL(A));
		sort(ALL(B));
		reverse(ALL(A));
		reverse(ALL(B));
		string C="";
		while(A.size()&&B.size()) {
			y=0;
			if(x==K) {
				y=1;
			}
			else if(x==-K) {
				y=0;
			}
			else if(A.back()<B.back()) {
				y=0;
			}
			else {
				y=1;
			}
			
			
			if(y==0) {
				x=max(0,x)+1;
				C+=A.back();
				A.pop_back();
			}
			else {
				x=min(0,x)-1;
				C+=B.back();
				B.pop_back();
			}
		}
		cout<<C<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}