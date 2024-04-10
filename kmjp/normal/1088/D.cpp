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


int RA=-1,RB=-1;
int ask(int c,int d) {
	int x;
	cout<<"? "<<c<<" "<<d<<endl;
	if(RA>=0) {
		if((RA^c)>(RB^d)) return 1;
		if((RA^c)<(RB^d)) return -1;
		return 0;
	}
	cin>>x;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int A=0,B=0;
	y=ask(A,B);
	for(i=29;i>=0;i--) {
		if(y==0) {
			x=ask(A^(1<<i),B);
			if(x<0) {
				A^=1<<i;
				B^=1<<i;
			}
		}
		else if(y>0) {
			x=ask(A^(1<<i),B);
			if(x==0) {
				A^=1<<i;
				y=0;
			}
			else if(x>0) {
				x=ask(A^(1<<i),B^(1<<i));
				if(x<0) {
					A^=1<<i;
				}
				
			}
			else if(x<0) {
				x=ask(A^(1<<i),B^(1<<i));
				if(x>0) {
					A^=1<<i;
					B^=1<<i;
				}
				else {
					A^=1<<i;
					y=-1;
				}
			}
		}
		else {
			x=ask(A,B^(1<<i));
			if(x==0) {
				B^=1<<i;
				y=0;
			}
			else if(x<0) {
				x=ask(A^(1<<i),B^(1<<i));
				if(x>0) {
					B^=1<<i;
				}
				
			}
			else if(x>0) {
				x=ask(A^(1<<i),B^(1<<i));
				if(x<0) {
					A^=1<<i;
					B^=1<<i;
				}
				else {
					B^=1<<i;
					y=1;
				}
			}
		}
	}
	cout<<"! "<<A<<" "<<B<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}