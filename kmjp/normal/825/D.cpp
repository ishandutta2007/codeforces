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

string S,T;
int N,M;
int cnt[256][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	M=T.size();
	FORR(c,S) cnt[c][0]++;
	FORR(c,T) cnt[c][1]++;
	while(1) {
		int need=0;
		FOR(i,26) if(cnt['a'+i][0]<cnt['a'+i][1]) need+=cnt['a'+i][1]-cnt['a'+i][0];
		if(need>cnt['?'][0]) break;
		FOR(i,26) {
			if(cnt['a'+i][0]<cnt['a'+i][1]) {
				cnt['?'][0]-=cnt['a'+i][1]-cnt['a'+i][0];
				cnt['a'+i][2]+=cnt['a'+i][1]-cnt['a'+i][0];
				cnt['a'+i][0]+=cnt['a'+i][1]-cnt['a'+i][0];
			}
			cnt['a'+i][0]-=cnt['a'+i][1];
		}
	}
	
	FORR(c,S) if(c=='?') {
		FOR(i,26) if(cnt['a'+i][2]) {
			c='a'+i;
			cnt['a'+i][2]--;
			break;
		}
		if(c=='?') c='a';
	}
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}