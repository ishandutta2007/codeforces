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

string S;
int L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	for(i=0;i+26<=L;i++) {
		int cnt[256]={};
		FOR(j,26) if(S[i+j]!='?') {
			if(cnt[S[i+j]]) break;
			cnt[S[i+j]]++;
		}
		if(j!=26) continue;
		FOR(j,26) if(S[i+j]=='?') {
			FOR(x,26) if(cnt['A'+x]==0) {
				S[i+j]='A'+x, cnt[S[i+j]]=1;
				break;
			}
		}
		FORR(c,S) if(c=='?') c='A';
		cout<<S<<endl;
		return;
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}