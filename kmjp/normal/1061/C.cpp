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
int A[101010];

ll num[1010100];
ll ret=0;
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	num[0]=1;
	FOR(i,N) {
		cin>>A[i];
		vector<int> X,Y;
		for(x=1;x*x<=A[i];x++) if(A[i]%x==0) {
			X.push_back(x);
			if(x*x!=A[i]) Y.push_back(A[i]/x);
		}
		while(X.size()) Y.push_back(X.back()),X.pop_back();
		FORR(v,Y) {
			ret+=num[v-1];
			(num[v]+=num[v-1])%=mo;
		}
		ret%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}