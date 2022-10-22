#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int N=1e7+9;
const int M=2e5+9;
int n,k,num=0;
int vis[N],pri[N],a[M];
bool b[N];
void work(){
	scanf("%d%d",&n,&k);
	int l=1,ans=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int x=a[i],y=1;
		while(x!=1){
			if(x/vis[x]%vis[x]==0)x=x/vis[x]/vis[x];
			else y*=vis[x],x/=vis[x];
		}
		a[i]=y;
		if(b[y]){
			for(int j=l;j<i;++j)b[a[j]]=0;
			l=i;
			ans++;
		}
		b[y]=1;
	}
	for(int i=1;i<=n;++i)b[a[i]]=0;
	printf("%d\n",ans);
}
int main(){
	for(int i=2;i<N;++i){
		if(!vis[i])vis[i]=i,pri[++num]=i;
		for(int j=1;1ll*i*pri[j]<N&&j<=num;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5 7
0 1 2 2 2
*/