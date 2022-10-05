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
vector<int> V[101010];
vector<int> R[101010];
int ma[101010];

int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		V[y].resize(W);
		R[y].resize(W);
		FOR(x,W) cin>>V[y][x];
	}
	for(y=H-1;y>=0;y--) {
		FOR(x,W) {
			if(y==H-1) R[y][x]=1,ma[y]=1;
			else {
				if(V[y][x]<=V[y+1][x]) R[y][x]=R[y+1][x]+1;
				else R[y][x]=1;
				ma[y]=max(ma[y],R[y][x]);
			}
		}
	}
	
	cin>>K;
	while(K--) {
		cin>>x>>y;
		if(ma[x-1]<y-x+1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}