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

int N,K;
string S;

char from[1010][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	from[0][1010]='+';
	FOR(i,N) {
		FOR(j,2020) if(from[i][j]!=0) {
			if(S[i]=='?'||S[i]=='W') {
				if(i==N-1 && j+1<=1010+K) from[i+1][j+1]='W';
				if(j+1<1010+K) from[i+1][j+1]='W';
			}
			if(S[i]=='?'||S[i]=='D') {
				from[i+1][j]='D';
			}
			if(S[i]=='?'||S[i]=='L') {
				if(i==N-1 && j-1>=1010-K) from[i+1][j-1]='L';
				if(j-1>1010-K) from[i+1][j-1]='L';
			}
		}
	}
	
	string S;
	int cur=-1;
	if(from[N][1010+K]) cur=1010+K;
	else if(from[N][1010-K]) cur=1010-K;
	
	if(cur==-1) {
		S="NO";
	}
	else {
		for(i=N;i>0;i--) {
			S+=from[i][cur];
			if(from[i][cur]=='W') cur--;
			else if(from[i][cur]=='L') cur++;
		}
		reverse(ALL(S));
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