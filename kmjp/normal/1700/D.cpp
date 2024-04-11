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

int N;
ll V[202020];
int Q;
ll T;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll mi=0;
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>V[i];
		S+=V[i];
		mi=max(mi,(S+i)/(i+1));
	}
	
	cin>>Q;
	while(Q--) {
		cin>>T;
		if(T<mi) {
			cout<<-1<<endl;
		}
		else {
			cout<<(S+(T-1))/T<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}