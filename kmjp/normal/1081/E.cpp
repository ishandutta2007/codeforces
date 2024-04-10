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
ll A[202020];

vector<ll> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6000001) M.push_back(1LL*i*i);
	
	cin>>N;
	ll cur=0;
	FOR(i,N/2) {
		cin>>A[i*2+1];
		ll nex=cur+1,R=nex;
		while(nex<=6000000) {
			while(R<5100000 && M[R]<nex*nex+A[i*2+1]) R++;
			if(R>5010000) return _P("No\n");
			if(M[R]==nex*nex+A[i*2+1]) break;
			nex++;
		}
		if(nex>6000000) return _P("No\n");
		
		A[i*2]=nex*nex-cur*cur;
		if(A[i*2]>10000000000000LL) return _P("No\n");
		cur=R;
	}
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<A[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}