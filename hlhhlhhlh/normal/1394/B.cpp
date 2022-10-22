// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,k1,k2;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,m,q,x,y,z;
int siz[maxn];
struct node{
	int x,y;
	node (int xx=0,int yy=0){
		x=xx; y=yy;
	}
};
vector < node > a[maxn];
bool cmp(node a,node b){
	return (a.y<b.y);
}
int mp[10][10][10][10],mpp[10][10];
bitset <200010> f[10][10];
int b[10];
long long ans;
void dfs(int x){
	if (x>q){
		ans++;
		return;
	}
	int fla=0;
	for (int i=1;i<=x;i++){
		if (mpp[x][i]==1) continue;
		fla=0;
		for (int j=1;j<=x-1;j++){
			if (mp[x][i][j][b[j]]==0) fla=1;
		}
		if (fla==1) continue;
		b[x]=i;
		dfs(x+1);
	}
}
int main(){
	
	n=read(); m=read(); q=read();
	for (i=1;i<=m;i++){
		x=read(); y=read(); z=read();
		siz[x]++;
		a[x].push_back( node(y,z) );
	}
	for (i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for (i=1;i<=q;i++){
		for (j=1;j<=i;j++){
			for (k=1;k<=n;k++){
				if (siz[k]==i){
					if (f[i][j][a[k][j-1].x]) mpp[i][j]=1;
					f[i][j][a[k][j-1].x]=1;
				}
			}
		}
	}
	for (i=1;i<=q;i++){
		for (j=1;j<=i;j++){
			for (k1=1;k1<=q;k1++){
				for (k2=1;k2<=k1;k2++){
					if ((f[i][j]|f[k1][k2])==(f[i][j]^f[k1][k2])){
						mp[i][j][k1][k2]=1; mp[k1][k2][i][j]=1;
					}
				}
			}
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	
	return 0;
}
/*
4 6 3
4 2 1
1 2 2
2 4 3
4 1 4
4 3 5
3 1 6

*/