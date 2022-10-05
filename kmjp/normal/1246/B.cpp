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

int N,K;
ll A[101010];
ll ret;

vector<pair<int,int>> enumpr(ll n) {
	vector<pair<int,int>> V;
	for(int i=2;i*i<=n;i++) if(n%i==0) {
		V.push_back({i,0});
		while(n%i==0) V.back().second++,n/=i;
		V.back().second %= K;
		if(V.back().second==0) V.pop_back();
	}
	if(n>1) V.push_back({n,1});
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	map<vector<pair<int,int>>,int> M;
	FOR(i,N) {
		cin>>A[i];
		//A[i]=i+1;
		
		vector<pair<int,int>> X=enumpr(A[i]);
		vector<pair<int,int>> Y=X;
		FORR(c,Y) c.second=K-c.second;
		ret+=M[Y];
		M[X]++;
		
	}
	
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}