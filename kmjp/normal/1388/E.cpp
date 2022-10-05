#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

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
int XL[2020],XR[2020],Y[2020];
ll LP[2020],RP[2020],Q[2020];
int A[2020];
double mi;

vector<pair<ll,ll>> P;
int rem[4040404];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) {
		return ((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//a
			if(b<=Q.back().second) return; //min
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(0^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};
ConvexHull<double> CHL,CHR;

bool cmp(pair<ll,ll> L,pair<ll,ll> R) {
	return L.first*R.second<R.first*L.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>XL[i]>>XR[i]>>Y[i];
	
	P.push_back({0,1});
	FOR(i,N) FOR(j,N) if(Y[i]<Y[j]) {
		P.push_back({XR[j]-XL[i],Y[j]-Y[i]});
		P.push_back({XL[j]-XR[i],Y[j]-Y[i]});
	}
	
	sort(ALL(P),cmp);
	P.erase(unique(ALL(P)),P.end());
	FOR(i,N) FOR(j,N) if(Y[i]<Y[j]) {
		pair<ll,ll> a={XR[j]-XL[i],Y[j]-Y[i]};
		x=lower_bound(ALL(P),a,cmp)-P.begin();
		a={XL[j]-XR[i],Y[j]-Y[i]};
		y=lower_bound(ALL(P),a,cmp)-P.begin();
		rem[y+1]++;
		rem[x]--;
	}
	
	vector<pair<double,double>> LC,RC;
	FOR(i,N) {
		LC.push_back({Y[i],-XL[i]});
		RC.push_back({-Y[i],XR[i]});
	}
	CHL.add(LC);
	CHR.add(RC);
	
	mi=1e19;
	FOR(i,P.size()) {
		if(i) rem[i]+=rem[i-1];
		if(rem[i]) continue;
		
		double a=1.0*P[i].first/P[i].second;
		
		mi=min(mi,CHR.query(a)+CHL.query(a));
	}
	
	
	
	_P("%.12lf\n",(double)mi);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}