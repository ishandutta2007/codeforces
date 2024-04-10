//Time Complexity : O(N*M)
//Space Complexity : O(N*M)
#include<bits/stdc++.h>
using namespace std;
const int N=100,M=100;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	char c=getchar();
	while(!isupper(c)){
		c=getchar();
	}
	vector<vector<int>>a(n),b(n);
	for(int i=0;i<=n-1;++i){
		a[i].resize(m);
		b[i].resize(m);
	}
	for(int i=0;i<=n-1;++i){
		string s;
		cin>>s;
		for(int j=0;j<=m-1;++j){
			switch(s[j]){
				case '.':
					a[i][j]=0;
					break;
				default:
					a[i][j]=s[j]-'A'+1;
					break;
			}
		}
	}
	int cnt=0;
	queue<pair<int,int>>q;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=m-1;++j){
			if(a[i][j]&&!b[i][j]){
				++cnt;
				q.push({i,j});
				while(!q.empty()){
					auto p=q.front();
					q.pop();
					int x=p.first,y=p.second;
					if(b[x][y]){
						continue;
					}
					b[x][y]=cnt;
					if(x>=1&&!b[x-1][y]&&a[x][y]==a[x-1][y]){
						q.push({x-1,y});
					}
					if(x<=n-2&&!b[x+1][y]&&a[x][y]==a[x+1][y]){
						q.push({x+1,y});
					}
					if(y>=1&&!b[x][y-1]&&a[x][y]==a[x][y-1]){
						q.push({x,y-1});
					}
					if(y<=m-2&&!b[x][y+1]&&a[x][y]==a[x][y+1]){
						q.push({x,y+1});
					}
				}
			}
		}
	}
	set<int>s;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=m-1;++j){
			if(a[i][j]==c-'A'+1){
				if(i>=1&&a[i-1][j]&&a[i-1][j]!=c-'A'+1){
					s.insert(b[i-1][j]);
				}
				if(i<=n-2&&a[i+1][j]&&a[i+1][j]!=c-'A'+1){
					s.insert(b[i+1][j]);
				}
				if(j>=1&&a[i][j-1]&&a[i][j-1]!=c-'A'+1){
					s.insert(b[i][j-1]);
				}
				if(j<=m-2&&a[i][j+1]&&a[i][j+1]!=c-'A'+1){
					s.insert(b[i][j+1]);
				}
			}
		}
	}
	int ans=s.size();
	printf("%d",ans);
	return 0;
}