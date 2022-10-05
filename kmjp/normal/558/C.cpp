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
int A[101010],B[101010];
vector<int> V;

int dodo(int a,int b) {
	int num=0;
	while(b%a || ((b/a)&(b/a-1))) num++, a/=2;
	b/=a;
	while(b>1) num++, b/=2;
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		y=A[i];
		while(y%2==0) y/=2;
		V.push_back(y);
	}
	sort(V.begin(),V.end());
	x=1;
	while(x*2<=V[0]) x*=2;
	FOR(i,V.size()) while(V[i]>=x*2) V[i]/=2;
	
	while(V.size()>1) {
		sort(V.begin(),V.end());
		V.erase(unique(ALL(V)),V.end());
		if(V.size()==1) break;
		FORR(r,V) r/=2;
	}
	
	ll mi=10101010;
	for(int v=V[0];v<=1<<20;v*=2) {
		ll tot=0;
		FOR(x,N) tot += dodo(A[x],v);
		mi=min(mi,tot);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}