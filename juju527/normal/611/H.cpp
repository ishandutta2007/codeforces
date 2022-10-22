//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5,maxm=10;
int n,m;
char s1[maxm],s2[maxm];
int num[maxm];
int e[maxm][maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool chk(){
	int S=(1<<m)-1;
	for(int s=1;s<S;s++){
		int nod=0,edg=0;
		for(int i=1;i<=m;i++)if((s>>(i-1))&1)nod+=num[i];
		for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)if(((s>>(i-1))&1)||((s>>(j-1))&1))edg+=e[i][j];
		if(nod>edg)return 0;
	}
	return 1;
}
int g[maxm][maxm];
bool can[maxm];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=i,d=0;
		while(x)x/=10,d++;
		num[d]++;m=max(m,d);
	}
	for(int i=1;i<n;i++){
		scanf("%s",s1);
		scanf("%s",s2);
		int u=strlen(s1),v=strlen(s2);
		if(u>v)swap(u,v);
		e[u][v]++;
	}
	if(!chk()){puts("-1");return 0;}
	int cnt=0;
	can[1]=1;num[1]--;
	while(cnt<n-1){
		for(int u=1;u<=m;u++){
			for(int v=u;v<=m;v++){
				if(!e[u][v])continue;
				e[u][v]--;
				bool tag=0;
				if(num[u]&&can[v]){
					num[u]--;
					if(chk())can[u]=1,g[u][v]++,tag=1;
					else num[u]++;
				}
				if(num[v]&&can[u]&&!tag){
					num[v]--;
					if(chk())can[v]=1,g[v][u]++,tag=1;
					else num[v]++;
				}
				if(!tag)e[u][v]++;else cnt++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int id=pow(10,i-1);
		if(i==1)id++;
		for(int j=1;j<=m;j++){
			if(j==i)continue;
			int s=pow(10,j-1);
			for(int k=1;k<=g[i][j];k++)printf("%d %d\n",s,id++);
		}
		int s=pow(10,i-1);
		for(int k=1;k<=g[i][i];k++)printf("%d %d\n",s,id++);
	}
    return 0;
}