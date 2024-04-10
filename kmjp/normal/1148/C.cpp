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
int P[303030];
int R[303030];
vector<pair<int,int>> V;

void hoge(int x,int y) {
	assert(abs(x-y)>=N/2);
	if(x>y) swap(x,y);
	swap(P[x],P[y]);
	R[P[y]]=y;
	R[P[x]]=x;
	V.push_back({x,y});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>P[i];
		R[P[i]]=i;
	}
	vector<int> C;
	FOR(i,N/2) {
		C.push_back(N/2-i);
		C.push_back(N/2+1+i);
	}
	FORR(c,C) {
		if(c<=N/2) {
			if(R[c]>=N/2+1) hoge(1,R[c]);
			hoge(R[c],N);
			hoge(c,R[c]);
		}
		else {
			if(R[c]<=N/2) hoge(R[c],N);
			hoge(1,R[c]);
			hoge(c,R[c]);
		}
	}
	
	_P("%d\n",V.size());
	FORR(v,V) _P("%d %d\n",v.first,v.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}