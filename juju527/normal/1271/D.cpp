#include <bits/stdc++.h>
using namespace std;
const int maxn=5005,inf=0x3f3f3f3f;
int a[maxn],b[maxn],c[maxn];
int t[maxn];
int f[maxn][maxn];
vector<int>e[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool cmp(int i,int j){
	return c[i]>c[j];
}
int main(){
//    freopen("CF1271D.in","r",stdin);
//    freopen("CF1271D.out","w",stdout);
    int n,m,k,w=0;
	n=read();m=read();k=read();w=k;
	for(int i=1;i<=n;i++){
		a[i]=read();b[i]=read();c[i]=read();
		t[i]=i;
		w+=b[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		t[v]=max(t[v],u);
	}
	for(int i=1;i<=n;i++)e[t[i]].push_back(i);
	for(int i=1;i<=n;i++)sort(e[i].begin(),e[i].end(),cmp);
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<e[i].size();j++)cout<<e[i][j]<<" ";cout<<endl;
//	}
	for(int i=0;i<=n;i++)for(int j=0;j<=w;j++)f[i][j]=-inf;
	f[0][k]=0;
	for(int i=1;i<=n;i++){
//		cerr<<i<<endl;
		for(int j=w-b[i];j>=a[i];j--)f[i][j+b[i]]=max(f[i][j+b[i]],f[i-1][j]);
//		cerr<<i<<endl;
		for(int j=0;j<=w;j++){
			if(f[i][j]==-inf)continue;
			int sum=0;
			for(int l=0;l<e[i].size();l++){
				if(j<l+1)break;
				sum+=c[e[i][l]];
				f[i][j-l-1]=max(f[i][j-l-1],f[i][j]+sum);
			}
		}
//		for(int j=0;j<=w;j++)cout<<f[i][j]<<" ";cout<<endl;
	}
	int ans=-1;
	for(int i=0;i<=w;i++)ans=max(ans,f[n][i]);
    printf("%d\n",ans);
	return 0;
}