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

int N,M,P;
string S;
string Q;

int le[505050],ri[505050];
int p[505050];
int is[505050];

void del(int cur) {
	is[cur]=0;
	if(P==cur) P=(ri[P]!=N+1)?ri[P]:le[P];
	ri[le[cur]] = ri[cur];
	le[ri[cur]] = le[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>P;
	cin>>S>>Q;
	vector<int> st;
	FOR(i,N) {
		le[i+1]=i;
		ri[i+1]=i+2;
		is[i+1]=1;
		if(S[i]=='(') st.push_back(i+1);
		else p[i+1]=st.back(),p[st.back()]=i+1,st.pop_back();
	}
	FORR(r,Q) {
		if(r=='R') P=ri[P];
		if(r=='L') P=le[P];
		if(r=='D') {
			x=P;
			y=p[P];
			for(i=min(x,y);i<=max(x,y);) {
				j=ri[i];
				del(i);
				i=j;
			}
		}
	}
	FOR(i,N) if(is[i+1]) _P("%c",S[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}