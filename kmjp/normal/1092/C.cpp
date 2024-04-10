#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S[202];
vector<int> V[101];
int did[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N-2) {
		cin>>S[i];
		V[S[i].size()].push_back(i);
	}
	
	FORR(a,V[1]) FORR(b,V[N-1]) {
		FOR(i,2) {
			string T;
			if(i==0) T=S[a]+S[b];
			else T=S[b]+S[a];
			
			FOR(j,2*N-2) {
				if(S[j]!=T.substr(0,S[j].size()) && S[j]!=T.substr(N-S[j].size())) break;
			}
			
			if(j!=2*N-2) continue;
			FOR(j,2*N-2) {
				if(S[j]==T.substr(0,S[j].size()) && did[S[j].size()]==0) {
					cout<<"P";
					did[S[j].size()]=1;
				}
				else cout<<"S";
			}
			cout<<endl;
			return;
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}