#include<bits/stdc++.h>
using namespace std;
const int N=3.5e5;
int n,k,now;
int a[N],f[2][N],last[N],pre[N];
int t[N*4],ad[N*4];
void add(int v,int x){
	t[v]+=x;
	ad[v]+=x;
}
void down(int v){
	if(ad[v]){
		add(v*2,ad[v]);
		add(v*2+1,ad[v]);
		ad[v]=0;
	}
}
void modify(int v,int l,int r,int x,int y){
	if(l==r){
		t[v]=y;
		return;
	}
	down(v);
	int m=l+r>>1;
	if(x<=m)modify(v*2,l,m,x,y);
	else modify(v*2+1,m+1,r,x,y);
	t[v]=max(t[v*2],t[v*2+1]);
}
void add2(int v,int l,int r,int pl,int pr){
	if(pl<=l&&r<=pr){
		add(v,1);
		return;
	}
	down(v);
	int m=l+r>>1;
	if(pl<=m)add2(v*2,l,m,pl,pr);
	if(m<pr)add2(v*2+1,m+1,r,pl,pr);
	t[v]=max(t[v*2],t[v*2+1]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),pre[i]=last[a[i]],last[a[i]]=i;
	for(int j=1;j<=k;++j){
		now^=1;
		for(int i=1;i<=n*4;++i)t[i]=ad[i]=0;
		for(int i=1;i<=n;++i){
			modify(1,1,n,i,f[!now][i-1]);
			add2(1,1,n,pre[i]+1,i);
			f[now][i]=t[1];
		}
	}
	printf("%d\n",f[now][n]);
}