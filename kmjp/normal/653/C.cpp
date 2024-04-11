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
int T[202020];
int NG[202020];
int S[202020];
int tar[202020];

int isng(int i) {
	if(i<0 || i>=N) return 0;
	if(i%2==0) {
		if(i && T[i]>=T[i-1]) return 1;
		if(i<N-1 && T[i]>=T[i+1]) return 1;
	}
	else {
		if(i && T[i]<=T[i-1]) return 1;
		if(i<N-1 && T[i]<=T[i+1]) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i];
	vector<int> V;
	FOR(i,N) {
		if(isng(i)) {
			NG[i]=1;
			V.push_back(i);
		}
		S[i+1]=S[i]+NG[i];
	}
	S[N+2]=S[N+1]=S[N];
	if(S[N]>6) return _P("0\n");
	int ret=0;
	FORR(r,V) {
		FOR(i,N) {
			if(NG[i]&&i<=r) continue;
			int ng=0;
			if(S[N]-S[max(i,r)+2]) continue;
			if(min(i,r)>=1 && S[min(i,r)-1]) continue;
			
			if(i-r>=3 && S[i-1]-S[r+2]) continue;
			if(r-i>=3 && S[r-1]-S[i+2]) continue;
			
			swap(T[i],T[r]);
			for(x=i-1;x<=i+1;x++) ng+=isng(x);
			for(x=r-1;x<=r+1;x++) ng+=isng(x);
			swap(T[i],T[r]);
			
			if(ng==0) ret++;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}