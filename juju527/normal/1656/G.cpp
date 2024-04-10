//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int a[maxn],p[maxn];
int cnt[maxn];
vec t[maxn];
int f[maxn];
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
bool vis[maxn];
int lst[maxn];
int main(){
    int T;
	T=read();
	while(T--){
		int n,num=0;
		n=read();
		for(int i=1;i<=n;i++)cnt[i]=0,t[i].clear();
		for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++,t[a[i]].eb(i);
		for(int i=1;i<=n;i++)if(cnt[i]&1)num++;
		if(num>1||(n%2==0&&num)||((n&1)&&cnt[a[(n+1)/2]]==1)){puts("NO");continue;}
		puts("YES");
		int it=0;
		for(int i=1;i<=n;i++){
			if(cnt[i]&1)p[(n+1)/2]=t[i].back(),t[i].pop_back(),cnt[i]--;
			while(cnt[i]){
				it++;
				p[it]=t[i].back();t[i].pop_back();cnt[i]--;
				p[n-it+1]=t[i].back();t[i].pop_back();cnt[i]--;
			}
		}
		for(int i=1;i<=n;i++)f[i]=i,lst[i]=vis[i]=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vec c;c.clear();
			vis[i]=1;c.eb(i);
			int x=p[i];
			while(x!=i)vis[x]=1,c.eb(x),f[x]=i,x=p[x];
			for(auto x:c){
				int y=lst[a[p[x]]];
				if(!y)lst[a[p[x]]]=x;
				else if(find(y)!=find(x)){
					f[find(x)]=find(y);
					swap(p[x],p[y]);
				}
			}
		}
		for(int i=1;i<=n;i++)vis[i]=0;
		int u=0,v=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			vis[i]=1;int x=p[i],y=0,z=0;
			if((n%2==0)||i!=(n+1)/2)y=i,z=n-i+1;
			while(x!=i){
				if((n%2==0)||x!=(n+1)/2)y=x,z=n-x+1;
				vis[x]=1,x=p[x];
			}
			if(!u&&!v){u=y,v=z;continue;}
			swap(p[u],p[y]);swap(p[y],p[v]);swap(p[v],p[z]);
		}
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		puts("");
	}
    return 0;
}