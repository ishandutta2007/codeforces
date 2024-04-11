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

int Q;
string S="What are you doing at the end of the world? Are you busy? Will you save us?";
string A="What are you doing while sending \"";
string B="\"? Are you busy? Will you send \"";
string C="\"?";

ll L[1010101];

char hoge(int N,ll K) {
	if(K>=L[N]) return '.';
	if(N==0) return S[K];
	if(K<A.size()) return A[K];
	K-=A.size();
	if(K<L[N-1]) return hoge(N-1,K);
	K-=L[N-1];
	if(K<B.size()) return B[K];
	K-=B.size();
	if(K<L[N-1]) return hoge(N-1,K);
	K-=L[N-1];
	return C[K];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	
	L[0]=S.size();
	FOR(i,100010) {
		L[i+1]=min(1LL<<60,(ll)(A.size()+B.size()+C.size())+L[i]*2);
	}
	
	FOR(i,Q) {
		int N;
		ll K;
		cin>>N>>K;
		cout<<hoge(N,K-1);
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}