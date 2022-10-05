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

int N,Q;
int ID[1010101],K[1010101],D[1010101];
int ret[1010101];
vector<int> R[1010101];
set<int> S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) S.insert(i);
	MINUS(ID);
	FOR(i,Q) {
		cin>>x>>y>>r;
		ID[x]=i;
		K[x]=y;
		D[x]=r;
	}
	for(i=1;i<=1010000;i++) {
		FORR(r,R[i]) S.insert(r);
		if(ID[i]>=0) {
			if(S.size()<K[i]) ret[ID[i]]=-1;
			else {
				FOR(x,K[i]) {
					auto k=*S.begin();
					S.erase(k);
					ret[ID[i]]+=k;
					R[i+D[i]].push_back(k);
				}
			}
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}