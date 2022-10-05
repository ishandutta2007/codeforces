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
int A[101010],B[101010];
pair<int,int> P[101010];
int dest[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	FOR(i,N) A[i]=P[i].first, B[i]=P[i].second;
	
	int ma=N;
	FOR(i,N) {
		x = lower_bound(A,A+i,A[i]-B[i])-A;
		while(x>=0 && A[x]>=A[i]-B[i]) x--;
		if(x>=0) dest[i]=dest[x];
		dest[i] += i-x-1;
		ma=min(ma,dest[i]+(N-1-i));
		
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}