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

int Q;
int N;
string S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N>>S[0]>>S[1];
		
		int cur=1;
		FOR(i,N) {
			
			if(S[0][i]<='2' && S[1][i]<='2') {
				continue;
			}
			else if(S[0][i]<='2' && S[1][i]>'2') {
				if(cur==2) {
					cur=0;
					break;
				}
			}
			else if(S[0][i]>'2' && S[1][i]<='2') {
				if(cur==1) {
					cur=0;
					break;
				}
			}
			else {
				cur=3-cur;
			}
			
		}
		
		if(cur==2) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}