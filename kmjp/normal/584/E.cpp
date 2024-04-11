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
int P[2020],Q[2020],R[2020];
vector<pair<int,int>> ret;
int C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i], R[Q[i]]=i;
	FOR(i,N) P[i]=R[P[i]];
	
	
	int cur;
	while(N) {
		//FOR(i,N) _P("%d ",P[i]); _P(" :: %d\n",C);
		FOR(cur,N) if(P[cur]==N-1) break;
		
		while(cur<N-1) {
			for(x=cur+1;x<=N-1;x++) {
				if((P[x]<x && P[x]<=cur) || x==N-1) {
					C += x-cur;
					ret.push_back({x+1,cur+1});
					swap(P[x],P[cur]);
					cur=x;
				}
			}
		}
		assert(P[N-1]==N-1);
		N--;
	}
	
	_P("%d\n",C);
	_P("%d\n",ret.size());
	FORR(r,ret) _P("%d %d\n",r.first,r.second);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}