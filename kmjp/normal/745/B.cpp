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

int H,W;
string S[505];
int L,R,T,B;
int tot;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	L=W;
	T=H;
	R=B=-1;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='X') {
			tot++;
			L=min(L,x);
			R=max(R,x);
			T=min(T,y);
			B=max(B,y);
		}
	}
	if((R-L+1)*(B-T+1)==tot) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}