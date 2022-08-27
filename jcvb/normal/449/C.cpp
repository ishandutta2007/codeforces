#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct ans{
	int u,v;
	}a[100005];int atot=0;
int vis[100005];
int pr[100005],bo[100005]={0},ptot=0;
void sieve(int n){
	for (int i=2;i<=n;i++){
		if(!bo[i])pr[ptot++]=i;
		for (int j=0;j<ptot && pr[j]*i<=n;j++){
			bo[pr[j]*i]=1;
			if(i%pr[j]==0)break;
		}
	}
}int n;
int tmp[100005];
int main()
{
	scanf("%d",&n);
	sieve(n);
	for (int i=1;i<ptot && pr[i]*2<=n;i++){
		int cnt=0,m;
		for (int j=pr[i];j<=n;j+=pr[i])if(!vis[j])tmp[cnt++]=j;
		if(cnt&1){
			a[atot++]=(ans){tmp[0],tmp[2]},vis[tmp[0]]=vis[tmp[2]]=1;
			for (int j=3;j<cnt;j+=2)a[atot++]=(ans){tmp[j],tmp[j+1]},vis[tmp[j]]=vis[tmp[j+1]]=1;
		}else{
			for (int j=0;j<cnt;j+=2)a[atot++]=(ans){tmp[j],tmp[j+1]},vis[tmp[j]]=vis[tmp[j+1]]=1;
		}
	}
	int cur=0;
	for (int i=2;i<=n;i+=2)if(!vis[i]){
		if(cur)a[atot++]=(ans){cur,i},cur=0;
		else cur=i;
	}printf("%d\n",atot);
	for (int i=0;i<atot;i++)printf("%d %d\n",a[i].u,a[i].v);
	return 0;
}