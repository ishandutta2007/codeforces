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
		vector<int> C;
		FOR(i,N) if(S[i]=='2') C.push_back(i);
		
		if(C.size()==1||C.size()==2) {
			cout<<"NO"<<endl;
			continue;
		}
		string R[50];
		FOR(i,N) {
			R[i]=string(N,'=');
			R[i][i]='X';
		}
		FOR(j,C.size()) {
			R[C[j]][C[(j+1)%C.size()]]='+';
			R[C[(j+1)%C.size()]][C[j]]='-';
		}
		cout<<"YES"<<endl;
		FOR(i,N) cout<<R[i]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}