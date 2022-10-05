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

int N,M;
ll X[303030],Y[303030];
vector<int> NG[303030];
ll tot[303030];
pair<ll,int> P[303030];


int hoge(int a,int b) {
	return min(X[a]+Y[b],X[b]+Y[a]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d%d",&x,&y);
		X[i]=x;
		Y[i]=y;
		P[i]={X[i]-Y[i],i};
	}
	
	sort(P,P+N);
	ll S=0;
	FOR(i,N) {
		x=P[i].second;
		tot[x]+=i*Y[x]+S;
		S+=X[x];
	}
	reverse(P,P+N);
	S=0;
	FOR(i,N) {
		x=P[i].second;
		tot[x]+=i*X[x]+S;
		S+=Y[x];
	}
	
	
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		x--,y--;
		tot[x]-=hoge(x,y);
		tot[y]-=hoge(x,y);
	}
	FOR(i,N) cout<<tot[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}