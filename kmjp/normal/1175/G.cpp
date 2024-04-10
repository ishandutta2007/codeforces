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
int A[20202];
ll from[20202];
ll to[20202];
int X[20202],Y[20202];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return ((A.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-A.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//a
			if(b>=Q.back().second) return; //min
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	V query(V x) {
		if(Q.empty()) return 1LL<<30;
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(((calc(Q[M],x)>=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

void hoge(int L,int R) {
	if(L+1==R) return;
	int M=(L+R)/2;
	hoge(L,M);
	hoge(M,R);
	
	int i;
	X[M-1]=0;
	Y[M]=0;
	for(i=M-1;i>=L;i--) Y[i]=max(Y[i+1],A[i]);
	for(i=M;i<R;i++) X[i]=max(X[i-1],A[i]);
	
	ConvexHull<ll> chtX,chtY;
	int cur=M-1;
	for(i=M;i<R;i++) {
		while(cur>=L && Y[cur+1]<=X[i]) {
			chtX.add(cur,from[cur]);
			cur--;
		}
		to[i]=min(to[i],chtX.query(-X[i])+i*X[i]);
	}
	cur=L;
	for(i=R-1;i>=M;i--) {
		while(cur<M && Y[cur+1]>=X[i]) {
			chtY.add(Y[cur+1],from[cur]-Y[cur+1]*cur);
			cur++;
		}
		to[i]=min(to[i],chtY.query(i));
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i+1];
		from[i+1]=1LL<<30;
	}
	
	while(K--) {
		FOR(i,N+1) to[i]=1LL<<30;
		hoge(0,N+1);
		swap(from,to);
	}
	
	cout<<from[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}