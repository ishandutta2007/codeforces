#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[202020];
ll ret;

int ma[202020];
int ok[402020];
int nextng[402020];
map<int,vector<int> > DD;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	/*
	int allsame=1;
	FOR(i,N-1) if(A[i]!=A[i-1]) allsame=0;
	if(allsame) {
		cout<<1LL*N*(N-1)<<endl;
		return;
	}
	*/
	for(int s=1;s<N;s++) DD[__gcd(s,N)].push_back(s);
	
	FORR(r,DD) {
		x = r.first;
		FOR(i,x) ma[i]=0;
		FOR(i,N) ma[i%x]=max(ma[i%x],A[i]);
		FOR(i,N) ok[i]=ok[i+N]=A[i]>=ma[i%x];
		
		nextng[2*N]=2*N;
		for(i=2*N-1;i>=0;i--) {
			nextng[i]=(ok[i]==0)?i:nextng[i+1];
			if(i<N && nextng[i]-i>=r.second[0]) ret += lower_bound(r.second.begin(),r.second.end(),nextng[i]-i+1)-r.second.begin();
		}
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}