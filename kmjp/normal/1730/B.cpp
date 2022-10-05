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

int Q,N;
ll X[101010],T[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,N) cin>>X[i];
		FOR(i,N) cin>>T[i];
		
		double L=0,R=1000000000;
		double AX=X[0];
		FOR(i,100) {
			double M=(L+R)/2;
			double AL=-1<<30;
			double AR=1<<30;
			FOR(j,N) {
				if(M<T[j]) break;
				AL=max(AL,X[j]-(M-T[j]));
				AR=min(AR,X[j]+(M-T[j]));
			}
			if(j==N&&AL<=AR) {
				R=M;
			}
			else {
				L=M;
				AX=AL;
			}
		}
		double AL=-1<<30;
		double AR=1<<30;
		FOR(j,N) {
			AL=max(AL,X[j]-(L-T[j]));
			AR=min(AR,X[j]+(L-T[j]));
		}
		
		
		_P("%.12lf\n",AL);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}