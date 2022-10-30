#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=3e5+5,p=20;
ll pow2[p],a[maxn],nex[maxn][p],mp[p][p];
int main(){
	int i,j,k,n,m;
	int x,y,t;
	bool flg;
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	pow2[0]=1;
	for (i=1;i<p;i++) pow2[i]=pow2[i-1]<<1;
	for (i=0;i<p;i++) for (j=0;j<p;j++) mp[i][j]=maxn;
	for (k=n-1;k>=0;k--){
		for (i=0;i<p;i++) nex[k][i]=(a[k]&pow2[i])?k:maxn;
		for (i=0;i<p;i++) if (a[k]&pow2[i])
			for (j=0;j<p;j++) if (!(a[k]&pow2[j]))
				nex[k][j]=min(nex[k][j],mp[i][j]);
		for (i=0;i<p;i++) if (a[k]&pow2[i])
			for (j=0;j<p;j++) if (!(a[k]&pow2[j]))
				mp[i][j]=min(mp[i][j],nex[k][j]);
		for (i=0;i<p;i++) if (a[k]&pow2[i])
			for (j=0;j<p;j++) if ((a[k]&pow2[j]))
				mp[i][j]=k;
	}
	while (m--){
		scanf("%d%d",&x,&y);
		x--; y--;
		if ((a[x]&a[y])>0){
			puts("Shi"); continue;
		}
		flg=false;
		for (j=0;j<p&&!flg;j++) if (a[y]&pow2[j])
			if (nex[x][j]<=y) flg=true;
		puts(flg?"Shi":"Fou");
	}
	return 0;
}