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

int H,W;
int A[2020],B[2020];
ll AS[2020],BS[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,H) cin>>A[i];
	FOR(i,H+1) AS[i]=1LL<<31;
	AS[0]=0;
	FOR(i,H) {
		ll s=0;
		for(j=1;i+j<=H;j++) s+=A[i+j-1], AS[j]=min(AS[j],s);
	}
	
	FOR(i,W) cin>>B[i];
	FOR(i,W+1) BS[i]=1LL<<31;
	AS[0]=0;
	FOR(i,W) {
		ll s=0;
		for(j=1;i+j<=W;j++) s+=B[i+j-1], BS[j]=min(BS[j],s);
	}
	
	cin>>x;
	int ma=0;
	for(i=1;i<=H;i++) for(j=1;j<=W;j++) if(AS[i]*BS[j]<=x) ma=max(ma,i*j);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}