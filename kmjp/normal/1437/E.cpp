#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[505050],B[505050];

vector<int> LIS(vector<int>& v) {
	int i,N=v.size();
	vector<int> dp(N,1<<30),id(N);
	FOR(i,v.size()) {
		id[i] = lower_bound(dp.begin(),dp.end(),v[i]+1) - dp.begin();
		dp[id[i]] = v[i];
	}
	int nl = *max_element(id.begin(),id.end());
	vector<int> ret(nl+1);
	FOR(i,N) if(id[N-1-i] == nl) ret[nl--] = v[N-1-i];
	return ret;
}

int hoge(int L,int R) {
	vector<int> C;
	int num=0;
	int i;
	for(i=L+1;i<R;i++) {
		if(A[i]<A[L]) num++;
		else if(A[i]>A[R]) num++;
		else C.push_back(A[i]);
	}
	if(C.size()) {
		int tc=C.size();
		num+=tc-LIS(C).size();
	}
	return num;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	A[0]=-1<<20;
	A[N+1]=1<<30;
	FOR(i,N) {
		scanf("%d",&A[i+1]);
		A[i+1]-=i;
	}
	B[0]=0;
	B[K+1]=N+1;
	FOR(i,K) scanf("%d",&B[i+1]);
	N+=2;
	K+=2;
	ll ret=0;
	FOR(i,K) if(i) {
		if(A[B[i]]<A[B[i-1]]) return _P("-1\n");
		ret+=hoge(B[i-1],B[i]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}