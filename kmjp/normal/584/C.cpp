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

int N,T;
string S[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	T=N-T;
	cin>>S[0]>>S[1];
	int dif=0;
	FOR(i,N) if(S[0][i]!=S[1][i]) dif++;
	int same=N-dif;
	
	S[2]=S[1];
	FOR(i,N) {
		if(S[0][i] == S[1][i]) {
			if(T) T--;
			else S[2][i] = (S[2][i]=='a')?'b':'a';
		}
	}
	
	T*=2;
	FOR(i,N) if(S[0][i] != S[1][i]) {
		if(T) {
			S[2][i]=S[T%2][i];
			T--;
		}
		else {
			char c='a';
			while(c==S[0][i] ||c==S[1][i]) c++;
			S[2][i]=c;
		}
	}
	
	if(T) return _P("-1\n");
	cout<<S[2]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}