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
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N<=3) {
			cout<<-1<<endl;
		}
		else if(N==4) {
			cout<<"3 1 4 2"<<endl;
		}
		else if(N==5) {
			cout<<"1 3 5 2 4"<<endl;
		}
		else if(N%2==0) {
			for(i=1;i<=N-5;i+=2) cout<<i<<" ";
			cout<<(N-1)<<" "<<(N-3)<<" "<<N<<" "<<(N-2)<<" "<<(N-4)<<" ";
			for(i=N-6;i>=2;i-=2) cout<<i<<" ";
			cout<<endl;
		}
		else {
			for(i=1;i<=N;i+=2) cout<<i<<" ";
			cout<<(N-3)<<" "<<(N-1)<<" ";
			for(i=N-5;i>=2;i-=2) cout<<i<<" ";
			cout<<endl;
		}
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}