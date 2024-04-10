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

int H,W;
int SY,SX;
int A,B;
string S[2010];
pair<int,int> D[2020][2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>SY>>SX;
	cin>>A>>B;
	FOR(y,H) cin>>S[y];
	
	priority_queue<pair<int,int>> PQ;
	MINUS(D);
	SY--,SX--;
	D[SY][SX]={A,B};
	PQ.push({(A+B),SY*10000+SX});
	int ret=0;
	
	while(PQ.size()) {
		int co=PQ.top().first;
		int cy=PQ.top().second/10000;
		int cx=PQ.top().second%10000;
		PQ.pop();
		
		if(D[cy][cx].first+D[cy][cx].second!=co) continue;
		ret++;
		int dy[4]={0,0,1,-1};
		int dx[4]={-1,1,0,0};
		FOR(i,4) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			pair<int,int> T=D[cy][cx];
			if(i==0) T.first--;
			if(i==1) T.second--;
			if(T.first<0 || T.second<0) continue;
			if(ty<0 || ty>=H || tx<0 || tx>=W) continue;
			if(S[ty][tx]=='*') continue;
			if(T>D[ty][tx]) {
				D[ty][tx]=T;
				PQ.push({(T.first+T.second),ty*10000+tx});
			}
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}