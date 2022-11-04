#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge{
	int i,j,w;
};

const int N=505,K=25;
int n,m,k;
int res[N][N][K];
vector<Edge>g[N][N];

void solve(int i,int j,int time,int val){
	if(res[i][j][k-time]>val){
		res[i][j][k-time]=val;
		if(k-time-2>=0)for(auto[i2,j2,w]:g[i][j])solve(i2,j2,time+2,val+w+w);
	}
}

main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
		for(int j=0;j<m-1;++j){
			int w;cin>>w;
			g[i][j].push_back({i,j+1,w});
			g[i][j+1].push_back({i,j,w});
		}
	for(int i=0;i<n-1;++i)
		for(int j=0;j<m;++j){
			int w;cin>>w;
			g[i][j].push_back({i+1,j,w});
			g[i+1][j].push_back({i,j,w});
		}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			for(int l=0;l<=k;++l)
				res[i][j][l]=INT_MAX;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			solve(i,j,0,0);
	for(int i=0;i<n;++i,cout<<"\n")
		for(int j=0;j<m;++j)
			cout<<(res[i][j][0]==INT_MAX?-1:res[i][j][0])<<" ";
}