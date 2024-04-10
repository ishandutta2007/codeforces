// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=600010;
int i,j,k;
int n,m;
int f1[maxn],f2[maxn],f3[maxn],th;
int fa[22][maxn],dept[maxn],f[maxn];
int l,r,mid,a[maxn],ha[maxn];
int x,y,z,thl,thr,xx;
long long tot[maxn],ans[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int getfa(int x,int k){
	int t1=1,t2=0;
	while (k!=0){
		if (k%(t1*2)/t1==1){
			k=k-t1;
			x=fa[t2][x];
		}
		t1=t1*2; t2++;
	}
	return x;
}
void dfs(int x,int fa){
	ans[x]=tot[f[x]]+ans[fa];
	int i=f1[x];
	while (i!=0){
		if (f2[i]!=fa){
			dfs(f2[i],x);
		}
		i=f3[i];
	}
}
void add(int x,int y){
	th++; f2[th]=y; f3[th]=f1[x]; f1[x]=th;
}
int main(){
	n=read();
	for (i=1;i<n;i++){
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	l=1; r=1; a[1]=1; ha[1]=1; f[1]=1;
	while (l<=r){
		i=f1[a[l]];
		while (i!=0){
			if (ha[f2[i]]==0){
				ha[f2[i]]=1;
				r++; a[r]=f2[i]; f[f2[i]]=r;
				fa[0][a[r]]=a[l];
				for (j=1;j<=20;j++) fa[j][a[r]]=fa[j-1][fa[j-1][a[r]]];
			}
			i=f3[i];
		}
		l++;
	}
	m=read();
	for (i=1;i<=m;i++){
		x=read(); y=read(); z=read(); y++; y=min(y,n+1);
		tot[f[x]]=tot[f[x]]+z; tot[f[x]+1]=tot[f[x]+1]-z;
		l=1; r=n; thl=1e9; thr=-1e9;
		while (l<=r){
			mid=(l+r)>>1; xx=getfa(a[mid],y);
			if (f[xx]<f[x]){
				l=mid+1;
			}
			else{
				if (f[xx]==f[x]) thl=mid;
				r=mid-1;
			}
		}
		l=1; r=n;
		while (l<=r){
			mid=(l+r)>>1; xx=getfa(a[mid],y);
			if (f[xx]<=f[x]){
				if (f[xx]==f[x]) thr=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		if (thl!=1e9){
			tot[thl]-=z; tot[thr+1]+=z;
		}
	}
	tot[0]=0;
	for (i=1;i<=n;i++){
		tot[i]+=tot[i-1];
	}
	dfs(1,0);
	for (i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}