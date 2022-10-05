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
string S[505050];
vector<int> E[505050][2];
int D[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			E[y][0].clear();
			E[y][1].clear();
			cin>>S[y];
			FOR(x,W) if(S[y][x]=='1') E[y][(y+x)%2].push_back(x);
		}
		int ret=0;
		FOR(i,2) {
			while(1) {
				priority_queue<pair<int,int>> Q;
				FOR(y,H) {
					if(E[y][i].size()) {
						D[y]=E[y][i].back();
						Q.push({D[y],y});
					}
					else {
						D[y]=-1;
					}
				}
				if(Q.empty()) break;
				ret++;
				while(Q.size()) {
					y=Q.top().second;
					x=Q.top().first;
					Q.pop();
					if(D[y]!=x) continue;
					if(y&&D[y-1]<D[y]-1) {
						D[y-1]=D[y]-1;
						Q.push({D[y-1],y-1});
					}
					if(y+1<H&&D[y+1]<D[y]-1) {
						D[y+1]=D[y]-1;
						Q.push({D[y+1],y+1});
					}
				}
				FOR(y,H) if(E[y][i].size()&&D[y]==E[y][i].back()) E[y][i].pop_back(),S[y][D[y]]='0';
			}
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}