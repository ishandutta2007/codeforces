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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	V set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int N,M,K;
ll C[202020];
int A[2],X[2][202020];
int mask[202020];
vector<pair<ll,int>> T[5];
vector<pair<ll,int>> P;
int id[202020];

BIT<ll,20> sum,can;
ll sum2;

void hoge(int v,int sgn) {
	sum2 += sgn*C[v];
	sum.add(id[v],-sgn*C[v]);
	can.add(id[v],-sgn*1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>C[i];
	FOR(x,2) {
		cin>>A[x];
		FOR(i,A[x]) {
			cin>>X[x][i];
			mask[X[x][i]-1] |= 1<<x;
		}
	}
	
	FOR(i,N) {
		T[mask[i]].push_back({C[i],i});
		T[4].push_back({C[i],i});
		P.push_back({C[i],i});
	}
	FOR(i,5) sort(ALL(T[i]));
	FOR(i,N) {
		id[T[4][i].second]=i+1;
		sum.add(id[T[4][i].second],C[T[4][i].second]);
		can.add(id[T[4][i].second],1);
	}
	ll mi=1LL<<60;
	FOR(i,min(K,(int)T[3].size())) hoge(T[3][i].second,1);
	
	for(i=K;i>=0;i--) {
		if(i<K && i<T[3].size()) hoge(T[3][i].second,-1);
		j=K-i;
		if(j) {
			if(j<=T[1].size()) hoge(T[1][j-1].second,1);
			if(j<=T[2].size()) hoge(T[2][j-1].second,1);
		}
		
		if(i<=T[3].size() && j<=T[1].size() && j<=T[2].size()) {
			int left=M-(i+j+j);
			if(left>=0) {
				x=can.lower_bound(left);
				mi=min(mi,sum2+sum.total(x));
			}
		}
		
	}
	
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}