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
string S,A="aA1";
int N;

bool ok(string S) {
	int mask=0;
	FORR(c,S) {
		if(c>='0' && c<='9') mask |= 1;
		if(c>='a' && c<='z') mask |= 2;
		if(c>='A' && c<='Z') mask |= 4;
	}
	return mask==7;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		
		if(ok(S)) {
			cout<<S<<endl;
			continue;
		}
		FOR(i,N) {
			string T=S;
			FOR(j,3) {
				T[i]=A[j];
				if(ok(T)) {
					cout<<T<<endl;
					goto out;
				}
			}
		}
		FOR(i,N-1) {
			string T=S;
			FOR(x,3) {
				FOR(y,3) {
					T[i]=A[x];
					T[i+1]=A[y];
					if(ok(T)) {
						cout<<T<<endl;
						goto out;
					}
				}
			}
		}
		out:
		;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}