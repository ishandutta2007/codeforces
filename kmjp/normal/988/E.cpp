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

int mi=101010;
string S;
unordered_map<string,int> SS;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int did[10]={};
	reverse(ALL(S));
	FORR(c,S) {
		if(c=='3') c='1';
		if(c=='4') c='1';
		if(c=='6') c='1';
		if(c=='8') c='1';
		if(c=='9') c='1';
		if(c=='2') c='7';
		did[c-'0']++;
		if(did[7]==2) {
			did[7]--;
			c='1';
		}
		if(did[5]==2) {
			did[5]--;
			c='1';
		}
	}
	reverse(ALL(S));
	SS[S]=0;
	queue<string> Q;
	Q.push(S);
	while(Q.size()) {
		S=Q.front();
		Q.pop();
		if(S.size()>=2) {
			if(S.substr(S.size()-2)=="00" || S.substr(S.size()-2)=="50" || S.substr(S.size()-2)=="75") {
				cout<<SS[S]<<endl;
				return;
			}
		}
		FOR(i,S.size()-1) {
			string T=S;
			swap(T[i],T[i+1]);
			if(T[0]=='0') continue;
			if(SS.count(T)) continue;
			SS[T]=SS[S]+1;
			Q.push(T);
		}
		
	}
	
	cout<<-1<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}