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
int X;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>X;
		int A=0;
		if(X==0) {
			_P("1 1\n");
			continue;
		}
		
		for(i=1;i<=100000;i++) if(1LL*i*i>X && 1LL*i*i*3/4<=X) {
			int dif=1LL*i*i-X;
			if((int)sqrt(dif+1e-5)*(int)sqrt(dif+1e-5)==dif) {
				x=sqrt(dif+1e-5);
				y=i/x;
				if(i/y==x) {
					_P("%d %d\n",i,y);
					break;
				}
			}
		}
		if(i>100000) _P("-1\n");
		
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}