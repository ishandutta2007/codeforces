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

int N,M;
int L[101010];
int pos[101010];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll S=0;
	cin>>N>>M;
	int ma=0;
	int ON=N;
	pos[M]=N+10;
	FOR(i,M) {
		cin>>L[i];
		S+=L[i];
	}
	if(S<N) return _P("-1\n");
	
	for(i=M-1;i>=0;i--) {
		pos[i]=min(pos[i+1]-1,N+1-L[i]);
	}
	if(pos[0]<1) return _P("-1\n");
	int dif=pos[0]-1;
	int mov=0;
	
	for(i=M-2;i>=0;i--) {
		int ma=min(dif,pos[i]-(pos[i+1]-L[i]));
		mov+=ma;
		dif-=ma;
		pos[i]-=mov;
	}
	FOR(i,M) cout<<pos[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}