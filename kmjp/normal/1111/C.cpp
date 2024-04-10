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

ll N,K,A,B;
int X[101010];
vector<int> V;

ll dfs(int L,int R,int a,int b) {
	if(a==b) return A;
	if(L+1==R) {
		return B*(b-a);
	}
	
	int M=(L+R)/2;
	ll ret=B*(R-L)*(b-a);
	int c=lower_bound(V.begin()+a,V.begin()+b,M)-V.begin();
	ll ret2=dfs(L,M,a,c)+dfs(M,R,c,b);
	
	return min(ret,ret2);
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>A>>B;
	FOR(i,K) {
		cin>>X[i];
		V.push_back(X[i]-1);
	}
	sort(ALL(V));
	
	cout<<dfs(0,1<<N,0,K)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}