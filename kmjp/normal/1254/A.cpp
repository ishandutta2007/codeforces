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

int T;
int H,W,K;
string S[101];
string A="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ret[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		int C[62]={};
		int NR=0;
		i=0;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) if(S[y][x]=='R') NR++;
		}
		FOR(i,NR) C[i%K]++;
		i=0;
		FOR(y,H) {
			FOR(j,W) {
				if(y%2==0) x=j;
				else x=W-1-j;
				if(i>=K) i=K-1;
				if(S[y][x]=='R') {
					S[y][x]=A[i];
					C[i]--;
					if(C[i]==0) i++;
				}
				else {
					S[y][x]=A[i];
				}
			}
			cout<<S[y]<<endl;
		}
		
		
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}