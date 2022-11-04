#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);

int n,m,gcnt,bcnt;
bool vis[50][50];
char b[50][52];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	int t;cin>>t;
	for(int tc=0;tc<t;++tc){
		int n,m;cin>>n>>m;
		for(int i=0;i<n;++i)cin>>b[i];
		memset(vis,0,sizeof(vis));
		gcnt=0;bcnt=0;
		bool pos=true;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(b[i][j]=='B'){
					++bcnt;
					for(int k=0;k<4;++k){
						int ny=i+dy[k];
						int nx=j+dx[k];
						if(ny>=0&&ny<n&&nx>=0&&nx<m){
							if(b[ny][nx]=='G')pos=false;
							if(b[ny][nx]=='.')b[ny][nx]='#';
						}
					}
				}
				if(b[i][j]=='G')++gcnt;
			}
		}
		if(!pos||(b[n-1][m-1]=='#'&&gcnt)){
			cout<<"No\n";
			continue;
		}
		queue<pair<int,int>>q;
		vis[n-1][m-1]=true;
		q.push({n-1,m-1});
		int found=0;
		while(!q.empty()){
			auto p=q.front();q.pop();
			if(b[p.first][p.second]=='G')++found;
			for(int i=0;i<4;++i){
				int ny=p.first+dy[i];
				int nx=p.second+dx[i];
				if(ny>=0&&ny<n&&nx>=0&&nx<m&&b[ny][nx]!='#'&&!vis[ny][nx]){
					vis[ny][nx]=true;
					q.push({ny,nx});
				}
			}
		}
		if(found==gcnt)cout<<"Yes\n";
		else cout<<"No\n";
	}
}