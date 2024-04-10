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

ll M[10101][10];
ll hoge=10004205361450474LL;

ll dp(ll L,int Q) {
	L=min(L,10000LL);
	if(M[L][Q]>=0) return M[L][Q];
	if(Q==0) return 0;
	if(Q==1) return L-1;
	
	ll la=L+dp(L,Q-1)+1;
	int i;
	FOR(i,L) la=la+1+dp(la+1,Q-1)+1;
	return M[L][Q]=la-L-1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(M);
	ll L=1;
	int Q=5;
	while(1) {
		vector<ll> V;
		if(Q==1) {
			FOR(i,min(10000LL,L)) V.push_back(L+i);
		}
		else {
			V.push_back(L+dp(L,Q-1)+1);
			FOR(i,min(10000LL,L)-1) V.push_back(V.back()+1+dp(V.back()+1,Q-1)+1);
		}
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
		
		cin>>x;
		if(x==-1) return;
		
		if(x>0) L=V[x-1]+1;
		Q--;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}