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

int L,L2;
char S[2][202020];
char hoge[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0]>>S[1];
	L=strlen(S[0]);
	
	FOR(j,2) {
		L2=L;
		while(L2%2==0) L2/=2;
		for(L2;L2<L;L2*=2) {
			for(x=0;x<L;x+=2*L2) {
				if(strncmp(S[j]+x,S[j]+x+L2,L2)>0) {
					memmove(hoge,S[j]+x,L2);
					memmove(S[j]+x,S[j]+x+L2,L2);
					memmove(S[j]+x+L2,hoge,L2);
				}
			}
		}
	}
	
	cout << ((strncmp(S[0],S[1],L)==0)?"YES":"NO")<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}