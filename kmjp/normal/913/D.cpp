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

int N,T;
int A[202020],B[202020];
pair<int,int> S[202020];

vector<int> hoge(int v) {
	int left=T,i;
	vector<int> V;
	
	FOR(i,N) {
		if(V.size()==v) return V;
		if(left<S[i].first) break;
		
		if(A[S[i].second]>=v) {
			left-=S[i].first;
			V.push_back(S[i].second);
		}
	}
	return V;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&T);
	FOR(i,N) {
		scanf("%d%d",&A[i],&B[i]);
		S[i]={B[i],i};
	}
	sort(S,S+N);
	
	int ma=0;
	for(i=20;i>=0;i--) {
		if(ma+(1<<i)>N) continue;
		auto v=hoge(ma+(1<<i));
		if(v.size()==ma+(1<<i)) ma+=1<<i;
	}
	
	auto v=hoge(ma);
	_P("%d\n",ma);
	_P("%d\n",ma);
	if(v.size()) {
		FOR(i,v.size()) _P("%d%c",v[i]+1,(i==v.size()-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}