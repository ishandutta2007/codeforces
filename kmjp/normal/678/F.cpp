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

const int DIV=2500;
int N;
ll T[303030],A[303030],B[303030];
int del[303030];
vector<int> cur,willadd;

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
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		if(cmptype==1) reverse(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>T[i];
		if(T[i]==1) cin>>A[i]>>B[i];
		if(T[i]==2) cin>>A[i], A[i]--;
		if(T[i]==3) cin>>A[i];
	}
	
	for(i=0;i<N;i+=DIV) {
		willadd.clear();
		ConvexHull<ll> ch;
		
		for(j=i;j<min(N,i+DIV);j++) if(T[j]==2 && A[j]<i) willadd.push_back(A[j]), del[A[j]]=2;
		vector<pair<ll,ll>> V;
		FORR(r,cur) if(del[r]==0) V.push_back({A[r],B[r]});
		ch.add(V);
		
		for(j=i;j<min(N,i+DIV);j++) {
			if(T[j]==1) willadd.push_back(j);
			if(T[j]==2) del[A[j]]=1;
			if(T[j]==3) {
				ll ma=-1LL<<60;
				FORR(r,willadd) if(del[r]!=1) ma=max(ma,A[r]*A[j]+B[r]);
				if(V.size()) ma=max(ma,ch.query(A[j]));
				if(ma==-1LL<<60) cout<<"EMPTY SET"<<endl;
				else cout<<ma<<endl;
			}
		}
		
		FORR(r,willadd) if(del[r]==0) cur.push_back(r);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}