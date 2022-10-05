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

int N,K,len;
string S;
int A[1010101];
pair<ll,int> D[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>len>>S;
	FOR(i,N) A[i]=(S[i]>='A'&&S[i]<='Z');
	if(1LL*K*len>=N) return _P("0\n");
	
	ll mi=N;
	int loop;
	FOR(loop,2) {
		
		int L=0,R=1<<20;
		ll ret=1LL<<60;
		while(L<R) {
			int M=(R+L)/2;
			FOR(i,N) {
				if(i==0) D[i]={0,0};
				else D[i]=D[i-1];
				D[i].first+=(A[i]^loop);
				
				D[i]=min(D[i], (i>=len) ? make_pair(D[i-len].first+M, D[i-len].second+1) : make_pair((ll)M,1));
			}
			if(D[N-1].second<=K) R=M, ret=max(0LL,D[N-1].first-1LL*K*M);
			else L=M+1;
		}
		mi=min(mi,ret);
		
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}