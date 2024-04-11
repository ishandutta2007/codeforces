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

int T,N,M;
string S[1010],R;

int tar[1010][4];
int pos[1010][4];

int from[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		MINUS(tar);
		MINUS(pos);
		
		FOR(y,N) {
			cin>>S[y];
			for(int len=2;len<=3;len++) {
				for(x=0;x+len<=M;x++) {
					int v=0;
					FOR(i,len) v=v*10+S[y][x+i]-'0';
					tar[v][len]=y+1;
					pos[v][len]=x+1;
				}
			}
		}
		cin>>R;
		
		MINUS(from);
		from[0]=0;
		for(x=0;x<M;x++) if(from[x]>=0) {
			for(int len=2;len<=3;len++) {
				if(x+len>M) continue;
				int v=0;
				FOR(i,len) v=v*10+R[x+i]-'0';
				if(tar[v][len]>=0) {
					from[x+len]=len*1000+v;
				}
			}
		}
		if(from[M]>=0) {
			vector<vector<int>> ret;
			int cur=M;
			while(cur>0) {
				x=from[cur]/1000;
				y=from[cur]%1000;
				ret.push_back({tar[y][x],pos[y][x],pos[y][x]+x-1});
				cur-=x;
			}
			reverse(ALL(ret));
			cout<<ret.size()<<endl;
			FORR(r,ret) cout<<r[1]<<" "<<r[2]<<" "<<r[0]<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}