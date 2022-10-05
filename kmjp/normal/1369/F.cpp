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

int T;
ll S[101010],E[101010];

int win[101010],lose[101010];

int canwin(ll s, ll e) {
	if(s==e) return 0;
	if(s>=e) return 1;
	if(e%2) {
		return !(s%2);
	}
	else {
		if(s*2>e) return (e-s)%2;
		if(4*s>e) return 1;
		return canwin(s,e/4);
	}
}

int canlose(ll s,ll e) {
	if(e<2*s) return 1;
	return canwin(s,e/2);
}


void solve() {
	int i,j,k,r,x,y; string s;
	
	cin>>T;
	FOR(i,T) {
		cin>>S[i]>>E[i];
		
		win[i]=canwin(S[i],E[i]);
		lose[i]=canlose(S[i],E[i]);
	}
	int w=1,l=0;
	
	FOR(i,T) {
		if(w==l) break;
		
		if(w) {
			w=lose[i];
			l=win[i];
		}
		else {
			w=!lose[i];
			l=!win[i];
		}
		
	}
	
	cout<<l<<" "<<w<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}