#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[505050],B[505050];
vector<pair<int,int> > V,V2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	A[N]=A[N-1];
	V.push_back({A[0],1});
	FOR(i,N+1) {
		if(A[i]!=V.back().first) V.push_back({A[i],0});
		V.back().second++;
	}
	FORR(r,V) {
		if(V2.empty()) V2.push_back(r);
		else if(r.second>1) V2.push_back(r);
		else {
			if(V2.back().first<10) V2.push_back({r.first+10,1});
			else V2.back().second++;
		}
	}
	
	int ma=0;
	int cur=0;
	FORR(r,V2) {
		if(r.first<10) {
			FOR(i,r.second) B[cur++]=r.first;
		}
		else {
			ma=max(ma,(r.second+1)/2);
			if(r.second&1) {
				FOR(i,r.second) B[cur++]=(r.first-10)^1;
			}
			else {
				FOR(i,r.second/2) B[cur++]=(r.first-10)^1;
				FOR(i,r.second/2) B[cur++]=(r.first-10);
			}
		}
	}
	_P("%d\n",ma);
	FOR(i,N) _P("%d ",B[i+1]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}