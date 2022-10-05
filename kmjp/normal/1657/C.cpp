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
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		reverse(ALL(S));
		int op=0;
		while(S.size()>1) {
			if(S[N-1]==S[N-2]) {
				S.pop_back();
				S.pop_back();
				N-=2;
				op++;
			}
			else if(S[N-1]=='('&&S[N-2]==')') {
				S.pop_back();
				S.pop_back();
				N-=2;
				op++;
			}
			else {
				for(i=N-3;i>=0;i--) if(S[i]==')') break;
				if(i==-1) break;
				N=i;
				S.resize(N);
				op++;
			}
		}
		cout<<op<<" "<<S.size()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}