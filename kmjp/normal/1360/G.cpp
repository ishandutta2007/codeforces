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
int H,W,A,B;
int R[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ZERO(R);
		cin>>H>>W>>A>>B;
		int cur=0;
		FOR(y,H) {
			FOR(x,A) {
				R[y][cur]=1;
				cur=(cur+1)%W;
			}
		}
		
		int ok=1;
		FOR(x,W) {
			int num=0;
			FOR(y,H) num+=R[y][x];
			if(num!=B) ok=0;
		}
		if(ok==0) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
			FOR(y,H) {
				FOR(x,W) cout<<R[y][x];
				cout<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}