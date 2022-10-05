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
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		FOR(i,N) if(S[i]=='0' && i<N/2) {
			cout<<(i+1)<<" "<<N<<" "<<(i+2)<<" "<<N<<endl;
			break;
		}
		if(i<N) continue;
		FOR(i,N) if(S[i]=='0' && i>=(N+1)/2) {
			cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
			break;
		}
		if(i<N) continue;
		if(N%2==1&&S[N/2]=='0') {
			cout<<1<<" "<<(N/2+1)<<" "<<(N/2+1)<<" "<<N<<endl;
		}
		else {
			cout<<1<<" "<<N-1<<" "<<2<<" "<<N<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}