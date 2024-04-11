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

int H,W,P;
int A[303][303];
vector<int> V[90909];
int dist[303][303];
int tdist[303][303];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>P;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		V[A[y][x]].push_back(y*1000+x);
		dist[y][x]=1<<30;
		if(A[y][x]==1) dist[y][x] = y+x;
	}
	for(i=1;i<P;i++) {
		if(V[i].size()*V[i+1].size()<=250000) {
			FORR(r1,V[i]) FORR(r2,V[i+1])
				dist[r2/1000][r2%1000] = min(dist[r2/1000][r2%1000], dist[r1/1000][r1%1000] + abs(r1/1000-r2/1000) + abs(r1%1000-r2%1000));
		}
		else {
			FOR(y,H) FOR(x,W) tdist[y][x]=1<<30;
			priority_queue<pair<int,int>> Q;
			FORR(r,V[i]) {
				tdist[r/1000][r%1000]=dist[r/1000][r%1000];
				Q.push({-tdist[r/1000][r%1000],r});
			}
			while(Q.size()) {
				int cy=Q.top().second/1000;
				int cx=Q.top().second%1000;
				int co=-Q.top().first;
				Q.pop();
				if(co!=tdist[cy][cx]) continue;
				FOR(j,4) {
					int dd[4]={1,0,-1,0};
					int ty=cy+dd[j];
					int tx=cx+dd[j^1];
					if(tx>=0 && tx<W && ty>=0 && ty<H && tdist[ty][tx] > co+1) {
						tdist[ty][tx] = co+1;
						Q.push({-tdist[ty][tx],ty*1000+tx});
					}
				}
			}
			FORR(r,V[i+1]) dist[r/1000][r%1000]=tdist[r/1000][r%1000];
		}
	}
	int mi=1<<30;
	FORR(r,V[P]) mi=min(mi,dist[r/1000][r%1000]);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}