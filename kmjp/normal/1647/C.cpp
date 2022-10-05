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
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			FORR(c,S[y]) c-='0';
		}
		
		if(S[0][0]==1) {
			cout<<-1<<endl;
			continue;
		}
		vector<vector<int>> ret;
		for(y=H-1;y>=1;y--) {
			FOR(x,W) if(S[y][x]) ret.push_back({y-1,x,y,x});
		}
		for(x=W-1;x>=0;x--) if(S[0][x]) ret.push_back({0,x-1,0,x});
		cout<<ret.size()<<endl;
		FORR(r,ret) cout<<r[0]+1<<" "<<r[1]+1<<" "<<r[2]+1<<" "<<r[3]+1<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}