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
const int NV=1<<19;
int sum[2*NV], ma[2*NV];
int V[202020];


void add(int cur,int v) {
	cur += NV;
	sum[cur]=ma[cur]=v;
	while(cur>1) cur>>=1, sum[cur]=sum[2*cur]+sum[2*cur+1], ma[cur]=max(ma[2*cur],sum[2*cur]+ma[2*cur+1]);
}

int query(int cur) {
	int tot=0;
	while(cur<NV) {
		cur*=2;
		if(ma[cur]<=tot) tot-=sum[cur], cur++;
	}
	return cur-NV;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>j;
		x = N+1-x;
		if(j==1) {
			cin>>V[x];
			add(x,1);
		}
		else {
			add(x,-1);
		}
		if(ma[1]<=0) cout<<-1<<endl;
		else cout<<V[query(1)]<<endl;;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}