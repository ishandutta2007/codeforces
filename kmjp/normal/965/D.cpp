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

int W,L;
ll A[101010];
ll num[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>L;
	for(i=1;i<W;i++) cin>>A[i];
	A[W]=1LL<<30;
	num[0]=1LL<<30;
	
	int pre=0;
	for(i=1;i<=W;i++) {
		if(pre<i-L) pre++;
		while(pre<i && A[i]>0) {
			x=min(num[pre],A[i]);
			num[pre]-=x;
			A[i]-=x;
			num[i]+=x;
			if(num[pre]==0) pre++;
		}
	}
	cout<<num[W]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}