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

int T,N,M;
string S;
int A[404040];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>S;
		ll C1=count(ALL(S),'1');
		if(C1*M%N) {
			cout<<-1<<endl;
			continue;
		}
		C1=C1*M/N;
		FOR(i,2*N) A[i+1]=A[i]+(S[i%N]-'0');
		
		FOR(i,N) if(A[i+M]-A[i]==C1) {
			if(i+M<=N) {
				cout<<1<<endl;
				cout<<(i+1)<<" "<<(i+M)<<endl;
			}
			else {
				cout<<2<<endl;
				cout<<1<<" "<<(i+M)%N<<endl;
				cout<<(i+1)<<" "<<N<<endl;
			}
			break;
		}
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}