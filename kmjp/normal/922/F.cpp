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

ll N,K;
vector<int> D[303030],E[303030];

int ok[303030],num[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll ma=0;
	vector<int> V;
	for(i=1;i<=N;i++) {
		V.push_back(i);
		for(j=i*2;j<=N;j+=i) {
			ma++;
			D[j].push_back(i);
			D[i].push_back(j);
		}
	}
	if(ma<K) return _P("No\n");
	srand(time(NULL));
	
	while(1) {
		int tar=ma-K;
		
		FOR(i,N) ok[i+1]=1,num[i+1]=D[i+1].size();
		FORR(v,V) if(ok[v] && num[v]<=tar) {
			ok[v]=0;
			tar-=num[v];
			FORR(d,D[v]) num[d]--;
		}
		if(tar==0) break;
		random_shuffle(ALL(V));
	}
	
	_P("Yes\n");
	int num=0;
	for(i=1;i<=N;i++) num+=ok[i];
	_P("%d\n",num);
	for(i=1;i<=N;i++) if(ok[i]) _P("%d ",i);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}