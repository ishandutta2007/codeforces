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
int H,W;
string S[61];
int A[70][70];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int mi=1010;
		int numP=0;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) numP+=S[y][x]=='P';
		}
		if(numP==0) mi=0;
		FOR(y,H) FOR(x,W) if(S[y][x]=='A') {
			int need=0;
			if(y) need++;
			if(x) need++;
			if(y<H-1) need++;
			if(x<W-1) need++;
			mi=min(mi,need);
		}
		FOR(y,H) {
			int num=0;
			FOR(x,W) if(S[y][x]=='P') num++;
			if(num==0) mi=min(mi,(y>0)+(y<H-1));
		}
		FOR(x,W) {
			int num=0;
			FOR(y,H) if(S[y][x]=='P') num++;
			if(num==0) mi=min(mi,(x>0)+(x<W-1));
		}
		
		
		if(mi>4) {
			cout<<"MORTAL"<<endl;
		}
		else {
			cout<<mi<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}