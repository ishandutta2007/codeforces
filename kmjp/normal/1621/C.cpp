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
int P[10101];
int Q[10101]; //={0,4,2,1,3};
int C[10101];

int ask(int i) {
	
	if(Q[1]) {
		i=C[i];
		static int C2[101010];
		int j;
		for(j=1;j<=N;j++) C2[j]=C[Q[j]];
		for(j=1;j<=N;j++) C[j]=C2[j];
		return i;
	}
	
	
	cout<<"? "<<i<<endl;
	cin>>i;
	return i;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(P);
		int step=0;
		
		FOR(i,N) C[i+1]=i+1;
		for(i=1;i<=N;i++) if(P[i]==0) {
			vector<int> S;
			while(1) {
				S.push_back(ask(i));
				if(S.size()>1&&S[0]==S.back()) break;
			}
			S.pop_back();
			FOR(j,S.size()) if(S[j]==i) break;
			FOR(x,S.size()) P[S[(j+x)%S.size()]]=S[(j+x+1)%S.size()];
			step+=S.size()+1;
		}
		
		cout<<"!";
		FOR(i,N) cout<<" "<<P[i+1];
		cout<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}