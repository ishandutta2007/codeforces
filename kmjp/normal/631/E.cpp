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
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((calc(Q[M],x)<=calc(Q[M+1],x))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

int N;
ll A[202020];
ll S[202020];
ll ma;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i+1];
		ma+=(i+1LL)*A[i+1];
		S[i+1]=S[i]+A[i+1];
	}
	
	ConvexHull<ll> ch;
	ll dif=0;
	ll L,R;
	// left shift
	for(L=N;L>=1;L--) {
		ch.add(L,-S[L]);
		dif=max(dif,ch.query(A[L])+S[L]-A[L]*L);
	}
	// right shift
	ch.Q.clear();
	ch.cmptype=0;
	for(R=1;R<=N;R++) {
		ch.add(R,-S[R-1]);
		dif=max(dif,ch.query(A[R])+S[R-1]-A[R]*R);
	}
	
	cout<<ma+dif<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}