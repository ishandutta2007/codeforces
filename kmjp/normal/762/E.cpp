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

template<class V> class BIT_var {
public:
	int ME;
	vector<V> bit;
	void init(int count) {
		ME=1;
		while((1<<ME)<=count*2) ME++;
		bit.clear();
		bit.resize(1<<ME);
	}
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};

int N,K;
int X[101010],R[101010],F[101010];
pair<int,int> P[101010];
vector<int> FX[10101];
BIT_var<int> bt[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>X[i]>>R[i]>>F[i];
		P[i]={R[i],i};
		FX[F[i]].push_back(X[i]);
	}
	for(i=1;i<=10000;i++) {
		FX[i].push_back(0);
		FX[i].push_back(1<<30);
		sort(ALL(FX[i]));
		bt[i].init(FX[i].size());
	}
	ll tot=0;
	sort(P,P+N);
	reverse(P,P+N);
	FOR(i,N) {
		x=P[i].second;
		
		for(int f=max(1,F[x]-K);f<=min(10000,F[x]+K);f++) {
			int upper=lower_bound(ALL(FX[f]),X[x]+R[x])-FX[f].begin();
			if(FX[f][upper]!=X[x]+R[x]) upper--;
			int lower=lower_bound(ALL(FX[f]),X[x]-R[x])-FX[f].begin()-1;
			tot += bt[f](upper)-bt[f](lower);
		}
		y=lower_bound(ALL(FX[F[x]]),X[x])-FX[F[x]].begin();
		bt[F[x]].add(y,1);
	}
	cout<<tot<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}