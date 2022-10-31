#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t,l[100500],r[100500],id[100500],it,num[100500],cur;
int g[405][100500],a[505],f[100500];
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}

void add2(int id,int l,int r){
	for(int i=l;i<=r;i++){
		g[id][num[i]]=su(g[id][num[i]],M-f[i-1]);
		if(num[i]+a[id]+1==m)f[cur]=su(f[cur],M-f[i-1]);
		num[i]++;
		g[id][num[i]]=su(g[id][num[i]],f[i-1]);
	}
}

void add(int l,int r){
	int i,j;it=0;
	for(i=1;i<=n;i+=300){
		j=i+300-1;it++;
		if(i>=l&&j<=r){
			if(a[it]<=m-1)f[cur]=su(f[cur],M-g[it][m-1-a[it]]);
			a[it]++;
		}
		else{
			add2(it,max(l,i),min(j,r));
		}
	}
}

void del2(int id,int l,int r){
	for(int i=l;i<=r;i++){
		g[id][num[i]]=su(g[id][num[i]],M-f[i-1]);
		if(num[i]+a[id]==m)f[cur]=su(f[cur],f[i-1]);
		num[i]--;
		g[id][num[i]]=su(g[id][num[i]],f[i-1]);
	}
}

void del(int l,int r){
	int i,j;it=0;
	for(i=1;i<=n;i+=300){
		j=i+300-1;it++;
		if(i>=l&&j<=r){
			if(a[it]<=m)f[cur]=su(f[cur],g[it][m-a[it]]);
			a[it]--;
		}
		else{
			del2(it,max(l,i),min(j,r));
		}
	}
}

int main() {
	f[0]=1;g[1][0]=1;
	for(i=1;i<=100005;i++){
		if((i%300)==1)it++;
		id[i]=it;
	}
	scanf("%d%d",&n,&m);m++;
	for(i=1;i<=n;i++){
		if(i==1)f[1]=1;
		else f[i]=f[i-1]*2%M;
		cur=i;
		scanf("%d",&k);
		del(l[k],r[k]);
		add(r[k]+1,i);
		l[k]=r[k]+1;r[k]=i;
		g[id[i+1]][0]=su(g[id[i+1]][0],f[i]);
	}
	printf("%d",f[n]);
}