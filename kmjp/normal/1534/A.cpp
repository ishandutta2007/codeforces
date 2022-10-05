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
string S[50];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		int C[2][2]={};
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) {
				if(S[y][x]=='R') {
					C[0][(x+y)%2]++;
				}
				if(S[y][x]=='W') {
					C[1][(x+y)%2]++;
				}
			}
		}
		if(C[0][0]&&C[0][1]) {
			cout<<"NO"<<endl;
			continue;
		}
		if(C[1][0]&&C[1][1]) {
			cout<<"NO"<<endl;
			continue;
		}
		if(C[0][0]&&C[1][0]) {
			cout<<"NO"<<endl;
			continue;
		}
		if(C[0][1]&&C[1][1]) {
			cout<<"NO"<<endl;
			continue;
		}
		int d=0;
		if(C[0][1]||C[1][0]) d=1;
		FOR(y,H) {
			FOR(x,W) {
				if((x+y)%2==d) S[y][x]='R';
				else S[y][x]='W';
			}
		}
		cout<<"YES"<<endl;
		FOR(y,H) cout<<S[y]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}