#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int N = 1010;
char g[N][N];
const int wx[4]={1,0,-1,0};
const int wy[4]={0,1,0,-1};
int d[N][N];
typedef pair<int,int> pi;
queue<pi> que;

int main()
{
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		scanf("%s",g[i]+1);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int c=0;
			for(int w=0;w<4;w++){
				int ni=i+wx[w],nj=j+wy[w];
				if(ni>=1&&ni<=n&&nj>=1&&nj<=m){
					c+=g[i][j]==g[ni][nj];
				}
			}
			// cerr << c << endl;
			if(c)d[i][j]=0,que.push(pi(i,j));
			// cerr << i << ":" << j << ":" << d[i][j] << endl;
		}
	}
	while(que.size()){
		int i=que.front().first,j=que.front().second;
		que.pop();
		for(int w=0;w<4;w++){
			int ni=i+wx[w],nj=j+wy[w];
			if(ni>=1&&ni<=n&&nj>=1&&nj<=m){
				if(-1==d[ni][nj])d[ni][nj]=d[i][j]+1,que.push(pi(ni,nj));
			}
		}
	}
	while(q--){
		int x,y;long long r;
		scanf("%d%d%lld",&x,&y,&r);
		r-=d[x][y];
		// cerr << r << endl;
		// cerr << d[x][y] << endl;
		if(d[x][y]<0||r<0)printf("%c\n",g[x][y]);
		else printf("%c\n",'0'+(char)((r%2)^(g[x][y]-'0')));
	}
}