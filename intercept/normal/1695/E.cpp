#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=6e5+9;
int n;
bool in[M];
vector<int>g[M];
vector<int>ans;
int tot=1,cur[M],head[M],vis[M];
struct E{
    int to,ne;
}e[M<<1];
void add(int u,int v){
    e[++tot]=E{v,head[u]};head[u]=tot;
    e[++tot]=E{u,head[v]};head[v]=tot;
}
void dfs(int u,int fa,int deep){
	in[u]=1;
	if(deep%2==1)ans.eb(fa),ans.eb(u);
    for(int&i=cur[u];i;i=e[i].ne){
        if(vis[i])continue;
        vis[i]=vis[i^1]=1;
        int v=e[i].to;
        dfs(v,u,deep+1);
    }
    if(deep%2==0&&deep)ans.eb(u),ans.eb(fa);
}
int a[M][2],b[M][2],c[M][2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	memcpy(cur,head,sizeof(cur));
	int l=0;
	for(int i=1;i<=n*2;++i){
		if(!in[i]){
			ans.clear();
			dfs(i,0,0);
			if(ans.size()<=2)continue;
			if(ans.size()%4==2){
				int x=l;
				l++;
				a[l][0]=ans[0];
				a[l][1]=ans[1];
				b[l][0]='L';
				b[l][1]='R';
				for(int j=2;j<ans.size();j+=2){
					if(j<ans.size()/2){
						a[++l][1]=ans[j];
						b[l][1]='U';
						a[++l][1]=ans[j+1];
						b[l][1]='D';
					}
					else{
						b[l][0]='D';
						a[l--][0]=ans[j];
						b[l][0]='U';
						a[l--][0]=ans[j+1];
					}
				}
				l=x+ans.size()/2;
				for(int j=x+1;j<l;j+=2){
					c[j][0]=c[j][1]='U';
					c[j+1][0]=c[j+1][1]='D';
				}
				c[l][0]='L';
				c[l][1]='R';
			}
			else if(ans.size()%4==0){
				int x=l;
				l++;
				a[l][0]=ans[0];
				a[l][1]=ans[1];
				b[l][0]='L';
				b[l][1]='R';
				for(int j=2;j<ans.size();j+=2){
					if(j<ans.size()/2){
						a[++l][1]=ans[j];
						b[l][1]='U';
						a[++l][1]=ans[j+1];
						b[l][1]='D';
					}
					else if(j==ans.size()/2){
						l++;
						a[l][1]=ans[j];
						a[l][0]=ans[j+1];
						b[l][0]='L';
						b[l][1]='R';
					}
					else{
						b[--l][0]='D';
						a[l][0]=ans[j];
						b[--l][0]='U';
						a[l][0]=ans[j+1];
						
					}
				}
				l=x+ans.size()/2;
				for(int j=x+1;j<=l;j+=2){
					c[j][0]=c[j][1]='U';
					c[j+1][0]=c[j+1][1]='D';
				}
			}
		}
	}
	if(l!=n){
		puts("-1");
		return 0;
	}
	printf("%d 2\n\n",n);
	for(int i=1;i<=n;++i){
		printf("%d %d\n",a[i][0],a[i][1]);
	}
	puts("");
	for(int i=1;i<=n;++i){
		putchar(b[i][0]);
		putchar(b[i][1]);
		puts("");
	}
	puts("");
	for(int i=1;i<=n;++i){
		putchar(c[i][0]);
		putchar(c[i][1]);
		puts("");
	}
	return 0;
}
/*
1
3 4
1 -1 1 1
-1 1 -1 1
1 -1 1 1

*/