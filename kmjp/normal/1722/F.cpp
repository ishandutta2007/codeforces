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

int T,H,W;
string S[55];

vector<pair<int,int>> C;
void dfs(int y,int x) {
	if(y<0||y>=H||x<0||x>=W) return;
	if(S[y][x]=='.') return;
	S[y][x]='.';
	C.push_back({y,x});
	int dy,dx;
	for(dy=y-1;dy<=y+1;dy++) for(dx=x-1;dx<=x+1;dx++) dfs(dy,dx);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		
		FOR(y,H) {
			cin>>S[y];
		}
		
		int ok=1;
		FOR(y,H) FOR(x,W) if(S[y][x]=='*') {
			C.clear();
			dfs(y,x);
			if(C.size()!=3) {
				ok=0;
			}
			else {
				if(max({C[0].first,C[1].first,C[2].first})-min({C[0].first,C[1].first,C[2].first})>=2) ok=0;
				if(max({C[0].second,C[1].second,C[2].second})-min({C[0].second,C[1].second,C[2].second})>=2) ok=0;
			}
			
		}
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}