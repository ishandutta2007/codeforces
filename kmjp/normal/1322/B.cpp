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

int N;
int A[401010];
int B[401010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	int ret=0;
	FOR(i,28) {
		FOR(j,N) B[j]=A[j]&((1<<(1+i))-1);
		sort(B,B+N);
		ll num=0;
		FOR(j,N) {
			if((B[j]&(1<<i))==0) {
				int L=(1<<i)-B[j];
				int R=(2<<i)-B[j];
				y=lower_bound(B+j+1,B+N,R)-B;
				x=lower_bound(B+j+1,B+N,L)-B;
				//cout<<"!"<<i<<j<<" "<<B[j]<<" "<<L<<" "<<R<<" "<<x<<" "<<y<<endl;
				num+=y-x;
			}
			else {
				int R=(3<<i)-B[j];
				y=lower_bound(B+j+1,B+N,R)-B;
				//cout<<"!"<<i<<j<<" "<<B[j]<<" "<<R<<" "<<y<<endl;
				num+=N-y;
			}
		}
		/*
		cout<<i<<" "<<num<<" "<<ret<<endl;
		FOR(j,N) cout<<B[j]<<" ";
		cout<<endl;
		*/
		if(num&1) ret^=1<<i;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}