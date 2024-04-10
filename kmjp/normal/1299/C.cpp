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
int A[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	vector<pair<long double,int>> V;
	FOR(i,N) {
		scanf("%d",&A[i]);
		V.push_back({A[i],1});
		while(V.size()>=2 && (V[V.size()-2].first>=V[V.size()-1].first)) {
			long double v=V[V.size()-2].first*V[V.size()-2].second+V[V.size()-1].first*V[V.size()-1].second;
			x=V[V.size()-1].second+V[V.size()-2].second;
			V.pop_back();
			V.pop_back();
			V.push_back({v/x,x});
		}
	}
	FORR(v,V) {
		FOR(i,v.second) _P("%.12lf\n",(double)v.first);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}