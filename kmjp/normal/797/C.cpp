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

string S,T,U;
int N;
char is[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	N=S.size();
	char c='z'+1;
	for(i=N-1;i>=0;i--) {
		is[i]=c;
		c=min(c,S[i]);
	}
	FOR(i,N) {
		while(T.size() && T.back()<=min(is[i],S[i])) {
			U.push_back(T.back());
			T.pop_back();
		}
		if(is[i]<S[i]) {
			T.push_back(S[i]);
		}
		else {
			while(T.size() && T.back()<=S[i]) {
				U.push_back(T.back());
				T.pop_back();
			}
			U.push_back(S[i]);
		}
	}
	while(T.size()) {
		U.push_back(T.back());
		T.pop_back();
	}
	cout<<U<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}