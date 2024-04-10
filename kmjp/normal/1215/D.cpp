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
string D;
int S;
int T[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		if(D[i]=='?') {
			T[i/(N/2)]++;
			T[2]++;
		}
		else {
			if(i>=N/2) {
				S-=D[i]-'0';
			}
			else {
				S+=D[i]-'0';
			}
		}
	}
	
	{
		int TS=S;
		int T2[2]={T[0],T[1]};
		int L=T[2]/2;
		x=min(L,T2[0]);
		TS+=9*x;
		T2[0]-=x;
		L-=x;
		T2[1]-=L;
		
		if(TS<0) TS=min(0,TS+T2[0]*9);
		TS=max(0,TS-T2[1]*9);
		if(TS) return _P("Monocarp\n");
	}
	{
		int TS=S;
		int T2[2]={T[0],T[1]};
		int L=T[2]/2;
		x=min(L,T2[1]);
		TS-=9*x;
		T2[1]-=x;
		L-=x;
		T2[0]-=L;
		
		if(TS>0) TS=max(0,TS-T2[1]*9);
		TS=min(0,TS+T2[0]*9);
		if(TS) return _P("Monocarp\n");
	}
	_P("Bicarp\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}