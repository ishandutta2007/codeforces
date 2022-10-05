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

string S;
int from[62][255][255];
int to[62][255][255];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	reverse(ALL(S));
	S+="0";
	memset(from,0x3f,sizeof(from));
	from[30][254][254]=0;
	int p,n;

	FOR(i,S.size()) {
		memset(to,0x3f,sizeof(to));
		for(int ca=1;ca<=59;ca++) for(p=254;p>=0;p--) for(n=254;n>=0;n--) if(from[ca][p][n]<=1<<20) {
			if(p) chmin(from[ca][p-1][n],from[ca][p][n]);
			if(n) chmin(from[ca][p][n-1],from[ca][p][n]);
			int val=ca-30+p-n;
			int nexc=val/10;
			int d=(val%10+10)%10;
			
			if(d&&val<0) nexc--;
			if(d==S[i]-'0') {
				chmin(to[30+nexc][p][n],from[ca][p][n]+p+n);
			}
			
		}
		swap(from,to);
	}
	
	int mi=1<<20;
	FOR(p,255) FOR(n,255) mi=min(mi,from[30][p][n]);
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}