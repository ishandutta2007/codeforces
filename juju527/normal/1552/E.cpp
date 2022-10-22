#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int maxn=105,maxnk=1e4+5;
bool vis[maxn];
int lst[maxn];
int pos[maxn][maxn];
pair<int,int> p[maxn];
int res[maxn][2];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int n,k;
	n=read();k=read();
	for(int i=1;i<=n*k;i++){
		int c;
		c=read();
		pos[c][++lst[c]]=i;
	}
	int v=ceil(1.0*n/(k-1));
	for(int i=2;i<=k;i++){
		for(int c=1;c<=n;c++)p[c]=make_pair(pos[c][i],c);
		sort(p+1,p+n+1);
		int cnt=0;
		for(int j=1;j<=n;j++){
			int c=p[j].se;
			if(vis[c])continue;
			vis[c]=1;
			res[c][0]=pos[c][i-1],res[c][1]=pos[c][i];
			cnt++;if(cnt==v)break;
		}
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",res[i][0],res[i][1]);
    return 0;
}