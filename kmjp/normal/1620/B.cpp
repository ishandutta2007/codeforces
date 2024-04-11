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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>
	T;
	while(T--) {
		vector<int> X1,X2,Y1,Y2;
		cin>>W>>H;
		cin>>k;
		X1.resize(k);
		FORR(x,X1) cin>>x;
		cin>>k;
		X2.resize(k);
		FORR(x,X2) cin>>x;
		cin>>k;
		Y1.resize(k);
		FORR(x,Y1) cin>>x;
		cin>>k;
		Y2.resize(k);
		FORR(x,Y2) cin>>x;
		ll ma=0;
		ma=max(ma,1LL*(X1.back()-X1[0])*H);
		ma=max(ma,1LL*(X2.back()-X2[0])*H);
		ma=max(ma,1LL*(Y1.back()-Y1[0])*W);
		ma=max(ma,1LL*(Y2.back()-Y2[0])*W);
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}