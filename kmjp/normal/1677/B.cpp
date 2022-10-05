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
int H,W;
string S;
int C[1010101],R[1010101],P[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>S;
		FOR(i,H*W) {
			C[i+1]=C[i]+(S[i]=='1');
			R[i+1]=0;
			P[i+1]=0;
		}
		
		FOR(i,W) {
			int x=0;
			FOR(y,H) {
				if(S[y*W+i]=='1') {
					P[y*W+i+1]++;
					break;
				}
			}
		}
		for(i=1;i<=H*W;i++) {
			if(C[i]-C[max(i-W,0)]) R[i]++;
			if(i>=W) R[i]+=R[i-W];
			P[i]+=P[i-1];
		}
		for(i=1;i<=H*W;i++) cout<<(R[i]+P[i])<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}