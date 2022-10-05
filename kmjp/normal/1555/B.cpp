#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T;
int W,H;
int X[2],Y[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int NW,NH;
		cin>>W>>H;
		cin>>X[0]>>Y[0]>>X[1]>>Y[1];
		cin>>NW>>NH;
		int CW=X[1]-X[0];
		int CH=Y[1]-Y[0];
		int mi=1<<30;
		
		
		if(CW+NW<=W) {
			mi=min(mi,NW-X[0]);
			mi=min(mi,X[1]-(W-NW));
		}
		if(CH+NH<=H) {
			mi=min(mi,NH-Y[0]);
			mi=min(mi,Y[1]-(H-NH));
		}
		mi=max(mi,0);
		if(mi==1<<30) mi=-1;
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}