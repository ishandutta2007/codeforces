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



template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=1; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		double a=(B.second-C.second)/(double)(C.first-B.first);
		double b=(A.second-B.second)/(double)(B.first-A.first);
		return cmptype^(a<=b);
	}
	void add(V a, V b) { // add ax+b
		Q.push_front({a,b});
		while(Q.size()>=3 && !dodo(Q[0],Q[1],Q[2]))
			Q[1]=Q[0], Q.pop_front();
	}
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((cmptype^((calc(Q[M],x)>=calc(Q[M+1],x))))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

ConvexHull<ll> ch;

int N;
int X[1010101],Y[1010101];
ll A[1010101];
pair<int,int> P[1010101];
ll dp[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>A[i];
		P[i]={X[i],i};
	}
	sort(P,P+N);
	
	ll ma=0;
	ch.add(0,0);
	FOR(i,N) {
		x=P[i].second;
		
		dp[x]=1LL*X[x]*Y[x]-A[x]+ch.query(Y[x]);
		ma=max(ma,dp[x]);
		ch.add(-X[x],dp[x]);
	}
	
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}