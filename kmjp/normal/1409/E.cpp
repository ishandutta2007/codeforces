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
int N,K;
vector<int> X;

int num[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		X.clear();
		FOR(i,N) {
			cin>>x;
			X.push_back(x);
			num[i]=0;
		}
		num[N]=0;
		FOR(i,N) cin>>x;
		sort(ALL(X));
		
		int ma=0;
		int ret=0;
		for(i=N-1;i>=0;i--) {
			x=lower_bound(ALL(X),X[i]+K+1)-X.begin();
			ret=max(ret,num[x]+x-i);
			num[i]=max(num[i+1],x-i);
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}