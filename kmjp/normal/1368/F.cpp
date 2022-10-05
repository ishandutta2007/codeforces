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
int A[1010];
int T[1010];


void solve() {
	int i,j,l,r,x,y; string s;
	
	cin>>N;
	int ma=-1,k=0;
	for(i=1;i<=N;i++) {
		int num=N-(N+(i-1))/i-(i-1);
		if(num>ma) ma=num, k=i;
	}
	cerr<<ma<<endl;
	
	FOR(i,N) T[i]=(i%k!=k-1);
	T[N-1]=0;
	FOR(i,8888) {
		int num=0;
		FOR(j,N) num+=(T[j]==1&&A[j]==0);
		cout<<num;
		FOR(j,N) if(T[j]==1&&A[j]==0) {
			cout<<" "<<(j+1);
			A[j]=1;
		}
		cout<<endl;
		if(num==0) return;
		cin>>x;
		assert(x>0);
		x--;
		FOR(j,num) A[(x+j)%N]=0;
	}
	cout<<0<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}