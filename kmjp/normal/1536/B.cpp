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
vector<string> C[6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	C[0].push_back("");
	for(i=1;i<=5;i++) {
		FOR(j,26) {
			string a=string(1,('a'+j));
			if(C[i].size()>=1<<20) break;
			FORR(c,C[i-1]) C[i].push_back(a+c);
		}
	}
	
	
	
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		set<string> T;
		FOR(i,N) {
			for(j=1;j<=5&&i+j<=N;j++) T.insert(S.substr(i,j));
		}
		
		string R;
		for(i=1;i<=5;i++) if(R.empty()) {
			FORR(c,C[i]) if(T.count(c)==0) {
				R=c;
				break;
			}
		}
		cout<<R<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}