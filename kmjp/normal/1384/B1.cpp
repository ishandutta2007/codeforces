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
int N,K,L;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>L;
		
		int CL=0,CR=2*K;
		FOR(i,N) {
			cin>>x;
			if(x>L) {
				CL=-1;
			}
			if(CL==-1) continue;
			if(x+K<=L) {
				CL=0,CR=2*K;
				continue;
			}
			
			y=K-(L-x);
			int DL=y;
			int DR=2*K-DL;
			
			if(CL==0 && CR==2*K) {
				CL=DL;
				CR=DR;
			}
			else {
				CL++;
				CR++;
				
				if(max(CL,DL)<=min(CR,DR)) {
					CL=max(CL,DL);
					CR=DR;
				}
				else {
					CL=-1;
				}
				
			}
			
		}
		if(CL>=0) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}