#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int Q,N,M;
string S,T;

int pref[5050][5050];
int suf[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>M>>S>>T;
		
		FOR(i,N+1) FOR(j,N+1) pref[i][j]=suf[i][j]=1<<20;
		FOR(i,N+1) {
			FOR(j,min(i,M)+1) {
				if(i==0||j==0) pref[i][j]=2*i;
				else {
					if(S[i-1]==T[j-1]) {
						pref[i][j]=min(pref[i][j],pref[i-1][j-1]);
					}
					if(pref[i-1][j]<1<<20) {
						pref[i][j]=min(pref[i][j],i+(i-j));
					}
				}
			}
		}
		for(i=N;i>=0;i--) {
			for(j=M;j>=max(0,M-(N-i));j--) {
				if(j==M) suf[i][j]=N-i;
				else if(i<N) {
					if(S[i]==T[j]) {
						suf[i][j]=min(suf[i][j],suf[i+1][j+1]+1);
					}
					if(suf[i+1][j]<1<<20) {
						suf[i][j]=min(suf[i][j],N-i);
					}
				}
			}
		}
		
		int ret=1<<20;
		FOR(i,N+1) FOR(j,M+1) {
			if(i==j&&pref[i][j]==0) {
				ret=min(ret,suf[i][j]);
			}
			else {
				ret=min(ret,suf[i][j]+1+pref[i][j]);
			}
			//cout<<"!"<<i<<j<<" "<<pref[i][j]<<" "<<suf[i][j]<<" "<<ret<<endl;
		}
		if(ret>1<<19) ret=-1;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}