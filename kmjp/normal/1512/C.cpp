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

int T,A,B;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>S;
		int N=A+B;
		FOR(i,N) {
			if(S[i]!=S[N-1-i]) {
				if(S[i]=='?') S[i]=S[N-1-i];
				else if(S[N-1-i]=='?') S[N-1-i]=S[i];
				else break;
			}
		}
		if(i!=N) {
			cout<<-1<<endl;
			continue;
		}
		FOR(i,N) {
			if(S[i]=='0') A--;
			if(S[i]=='1') B--;
		}
		FOR(i,N) {
			if(S[i]=='?') {
				if(i==N-1-i) {
					if(A%2==1) A--,S[i]='0';
					else if(B%2==1) B--,S[i]='1';
				}
				else {
					if(A>=2) A-=2, S[i]=S[N-1-i]='0';
					else if(B>=2) B-=2, S[i]=S[N-1-i]='1';
				}
			}
		}
		if(A||B) {
			cout<<-1<<endl;
		}
		else {
			cout<<S<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}