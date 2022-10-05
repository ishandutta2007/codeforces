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

int T,N;
int A[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			A[i]=abs(A[i]);
		}
		sort(A,A+N);
		
		if(A[0]==0) {
			cout<<"YES"<<endl;
			continue;
		}
		
		int ok=0;
		for(int mask=1;mask<1<<N;mask++) {
			int S=0;
			FOR(i,N) if(mask&(1<<i)) S+=A[i];
			int sm=((1<<N)-1)^mask;
			for(int sm2=sm;sm2>=0;sm2--) {
				sm2&=sm;
				int SS=0;
				FOR(i,N) if(sm2&(1<<i)) SS+=A[i];
				if(S==SS) ok=1;
			}
		}
		
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}