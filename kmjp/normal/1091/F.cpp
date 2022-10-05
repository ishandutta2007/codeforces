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
ll L[101010],LS[101010];
string S;
map<ll,ll> G,W;
int C[202020][2]={};
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	FOR(i,N) {
		cin>>L[i];
		LS[i+1]=LS[i]+L[i];
	}
	ret=LS[N];
	
	cin>>S;
	FOR(i,N) {
		C[i+1][0]=C[i][0];
		C[i+1][1]=C[i][1];
		if(S[i]=='W') {
			C[i+1][0]++;
			W[i]=L[i];
		}
		else if(S[i]=='G') {
			C[i+1][1]++;
			G[i]=L[i];
		}
		else {
			ll a=L[i];
			while(a && W.size()) {
				ll b=min(a,W.rbegin()->second);
				a-=b;
				W.rbegin()->second-=b;
				ret+=b*2;
				if(W.rbegin()->second==0) W.erase(W.rbegin()->first);
			}
			while(a && G.size()) {
				ll b=min(a,G.rbegin()->second);
				a-=b;
				G.rbegin()->second-=b;
				ret+=b*4;
				if(G.rbegin()->second==0) G.erase(G.rbegin()->first);
			}
			if(C[i][0]) {
				ret+=a*3;
			}
			else {
				ret+=a*5;
			}
			
		}
	}
	
	while(W.size()||G.size()) {
		if(W.size() && (G.empty()|| (W.rbegin()->first>G.rbegin()->first))) {
			ret+=W.rbegin()->second;
			W.erase(W.rbegin()->first);
		}
		else {
			while(G.rbegin()->second>0 && W.size()) {
				ll mi=min(G.rbegin()->second,W.rbegin()->second);
				ret+=mi*2;
				G.rbegin()->second-=mi;
				W.rbegin()->second-=mi;
				if(W.rbegin()->second==0) W.erase(W.rbegin()->first);
			}
			ret+=G.rbegin()->second*2;
			G.erase(G.rbegin()->first);
			
		}
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}