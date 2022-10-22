#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=105;
int n;
char s[maxn];
//a[x][y][z]:d(x,z)=d(y,z) or not.
bool a[maxn][maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vec t[maxn];
vec e[maxn];
bool use[maxn];
int f[maxn];
int dep[maxn];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(auto y:e[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
	return ;
}
bool chk(){
	for(int i=2;i<=n;i++)e[f[i]].eb(i),e[i].eb(f[i]);
	for(int z=1;z<=n;z++){
		dfs(z,0);
		for(int x=1;x<=n;x++)for(int y=x+1;y<=n;y++)if(a[x][y][z]!=(dep[x]==dep[y]))return 0;
	}
	return 1;
}
int main(){
    int T;
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				scanf("%s",s+1);
				for(int k=1;k<=n;k++)a[i][i+j][k]=a[i+j][i][k]=s[k]-'0';
			}
		}
		for(int i=1;i<=n;i++)t[i].clear();
		int d=0;
		for(int i=2;i<=n;i++){
			if(!d){t[++d].eb(i);continue;}
			bool tag=0;
			for(int j=1;j<=d;j++)if(a[t[j][0]][i][1]){tag=1;t[j].eb(i);break;}
			if(tag)continue;
			t[++d].eb(i);
		}
		bool res=0;
		for(int u=1;u<=d;u++){
			for(int x=1;x<=n;x++)e[x].clear();
			for(int x=1;x<=d;x++)use[x]=0;
			use[u]=1;for(auto x:t[u])f[x]=1;
			vec p=t[u];
			bool can=1;
			for(int i=2;i<=d;i++){
				bool op=0;
				for(int v=1;v<=d;v++){
					if(use[v])continue;
					bool flag=1;
					for(auto x:t[v]){
						bool tag=0;
						for(auto fa:p)if(a[f[fa]][x][fa]){f[x]=fa;tag=1;break;}
						if(!tag){flag=0;break;}
					}
					if(!flag)continue;
					use[v]=1;p=t[v];op=1;
					break;
				}
				if(!op){can=0;break;}
			}
			if(!can)continue;
			if(!chk())continue;
			res=1;break;
		}
		if(res){
			puts("Yes");
			for(int i=2;i<=n;i++)printf("%d %d\n",f[i],i);
		}
		else puts("No");
	}
    return 0;
}