#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string S;
int L,K;
char ispar[5050][5050];
string res;
deque<int> D[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>K;
	L=S.size();
	for(int len=0;len<L;len++) {
		FOR(x,L) if(x+len<L) {
			if(S[x]==S[x+len] && (len<=3 || ispar[x+2][x+len-2])) ispar[x][x+len]=1, D[x].push_back(x+len);
		}
	}
	
	FOR(i,L) {
		int fin=0,a=0,b=0;
		FOR(x,L) if(D[x].size()) {
			if(D[x][0]==x+i-1) fin++,D[x].pop_front();
			if(D[x].empty()) continue;
			if(S[x+i]=='a') a+=D[x].size();
			else b+=D[x].size();
		}
		if(K<=fin) break;
		K-=fin;
		if(K<=a) {
			res+="a";
			FOR(x,L) if(D[x].size() && S[x+i]=='b') D[x].clear();
		}
		else {
			K-=a;
			res+="b";
			FOR(x,L) if(D[x].size() && S[x+i]=='a') D[x].clear();
		}
	}
	
	cout<<res<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}