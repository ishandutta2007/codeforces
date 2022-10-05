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

int N;
int le[202000],ri[202000];
int lenma[202000];
int H[202000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	stack<pair<int,int> > S;
	S.push(make_pair(-1,-1));
	
	cin>>N;
	
	FOR(i,N) {
		cin>>H[i];
		while(S.top().first > H[i]) ri[S.top().second]=i-S.top().second, S.pop();
		S.push(make_pair(H[i],i));
	}
	while(S.size()>1) ri[S.top().second]=N-S.top().second, S.pop();
	
	S.pop();
	S.push(make_pair(-1,N));
	for(i=N-1;i>=0;i--) {
		cin>>H[i];
		while(S.top().first > H[i]) le[S.top().second]=S.top().second-i, S.pop();
		S.push(make_pair(H[i],i));
	}
	while(S.size()>1) le[S.top().second]=S.top().second+1, S.pop();
	
	FOR(i,N) lenma[le[i]+ri[i]-1]=max(lenma[le[i]+ri[i]-1], H[i]);
	
	for(i=N;i>=1;i--) lenma[i]=max(lenma[i],lenma[i+1]);
	FOR(i,N) _P("%d ",lenma[i+1]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}