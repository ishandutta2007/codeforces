#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int maxn=1e6+5,maxm=(1<<13);
int f[maxm];
vector<int> g[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int n,W=(1<<13);
	n=read();
	for(int i=0;i<W;i++)f[i]=W;
	for(int i=1;i<W;i++)g[i].eb(0);
	f[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		for(int j=0;j<g[x].size();j++){
			int v=g[x][j],w=v^x;
//			cerr<<i<<" "<<v<<" "<<w<<endl;
			if(f[w]>x){
				int lim=min(f[w],W-1);
				for(int k=x+1;k<=lim;k++)g[k].eb(w);
				f[w]=x;
			}
		}
		g[x].clear();
	}
	int num=0;
	for(int i=0;i<W;i++)if(f[i]<W)num++;
	printf("%d\n",num);
    for(int i=0;i<W;i++)if(f[i]<W)printf("%d ",i);
	return 0;
}