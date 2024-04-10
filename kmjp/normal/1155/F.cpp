#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<int> E[15];
int EM[15];
vector<int> path[1<<14][14][14];
vector<pair<int,int>> R[1<<14];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		EM[x-1] |= 1<<(y-1);
		EM[y-1] |= 1<<(x-1);
	}
	
	FOR(i,N) path[1<<i][i][i].push_back(i);
	
	int mask;
	FOR(mask,1<<N) {
		FOR(x,N) FOR(y,N) if(path[mask][x][y].size()) {
			FORR(e,E[y]) {
				if(e==x) {
					if(path[mask][x][y].size()>=3&&path[mask][x][x].empty()) {
						path[mask][x][x]=path[mask][x][y];
						path[mask][x][x].push_back(x);
					}
				}
				else if((mask&(1<<e))==0 && path[mask|(1<<e)][x][e].empty()) {
					path[mask|(1<<e)][x][e]=path[mask][x][y];
					path[mask|(1<<e)][x][e].push_back(e);
				}
			}
		}
	}
	FOR(mask,1<<N) if(path[mask][0][0].size()) {
		FOR(j,path[mask][0][0].size()-1) R[mask].push_back({path[mask][0][0][j],path[mask][0][0][j+1]});
	}
	
	
	FOR(mask,1<<N) {
		for(int from=(mask-1)&mask; from>0; from=(from-1)&mask) if(R[from].size()) {
			int oth=mask^from;
			FOR(x,N) FOR(y,N) if(path[oth][x][y].size() && (EM[x]&from) && (EM[y]&from)) {
				int tx=0,ty=0;
				if(R[mask].size() && R[mask].size()<=R[from].size()+path[oth][x][y].size()+1) continue;
				while(((1<<tx)&from&EM[x])==0 && tx<N) tx++;
				while(((((1<<ty)&from&EM[y])==0)||(x==y&&tx==ty))&&ty<N) ty++;
				if(tx>=N || ty>=N) continue;
				R[mask]=R[from];
				R[mask].push_back({x,tx});
				R[mask].push_back({y,ty});
				FOR(i,path[oth][x][y].size()-1) R[mask].push_back({path[oth][x][y][i],path[oth][x][y][i+1]});
			}
		}
	}
	
	cout<<R[(1<<N)-1].size()<<endl;
	FORR(r,R[(1<<N)-1]) cout<<(r.first+1)<<" "<<(r.second+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}