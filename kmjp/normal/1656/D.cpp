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
ll N;

int ok[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if((N&(N-1))==0) {
			cout<<-1<<endl;
		}
		else if(N%2==1) {
			cout<<2<<endl;
		}
		else {
			ll a=1;
			while(N%(a*2)==0) a*=2;
			__int128 b=N/a;
			
			if(b*(b+1)/2<=N) {
				cout<<(ll)b<<endl;
			}
			else {
				cout<<a*2<<endl;
			}
			
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}