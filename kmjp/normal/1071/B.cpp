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

int N,K;
string S[2010];
int D[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) cin>>S[y];
	MINUS(D);
	D[0][0]=K;
	FOR(y,N) FOR(x,N) if(D[y][x]>0) {
		if(S[y][x]!='a') {
			S[y][x]='a';
			D[y][x]--;
		}
		if(y<N-1) D[y+1][x]=max(D[y+1][x],D[y][x]);
		if(x<N-1) D[y][x+1]=max(D[y][x+1],D[y][x]);
	}
	
	string R;
	set<pair<int,int>> V;
	V.insert({0,0});
	while(V.size()) {
		R+=S[V.begin()->second][V.begin()->first];
		
		set<pair<int,int>> W;
		char p='z'+1;
		FORR(v,V) {
			y=v.second+1, x=v.first;
			if(y<N) {
				if(S[y][x]<p) p=S[y][x], W.clear();
				if(S[y][x]==p) W.insert({x,y});
			}
			y=v.second, x=v.first+1;
			if(x<N) {
				if(S[y][x]<p) p=S[y][x], W.clear();
				if(S[y][x]==p) W.insert({x,y});
			}
		}
		
		swap(W,V);
	}
	cout<<R<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}