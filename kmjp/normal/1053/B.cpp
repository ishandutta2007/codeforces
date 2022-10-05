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
ll A[303030];
int C[303030],SC[303030];
ll tot[303030][2];
ll ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	tot[0][0]=1;
	
	for(i=1;i<=N;i++) {
		cin>>A[i];
		//A[i]=(1LL<<60)-1;
		C[i]=__builtin_popcountll(A[i]);
		SC[i]=SC[i-1]+C[i];
		
		tot[i][0]=tot[i-1][0];
		tot[i][1]=tot[i-1][1];
		tot[i][SC[i]%2]++;
		
		
		int sum=C[i];
		int ma=C[i];
		int cur=i;
		while(cur>0 && sum<=120) {
			if(ma*2<=sum && sum%2==0) ret++;
			cur--;
			sum+=C[cur];
			ma=max(ma,C[cur]);
		}
		if(cur>0) ret+=tot[cur-1][SC[i]%2];
	}
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}