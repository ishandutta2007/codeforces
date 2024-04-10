#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=2e5;
const int M=2e5+9;
int n,q,ans=1,num=0;
int pri[M],vis[M],mi[M];
map<int,int>mp[M],cnt[M];
void change(int id,int x){
	cnt[x][mp[id][x]]--;
	if(cnt[x][mp[id][x]]==0&&mp[id][x]==mi[x]){
		ans=1ll*ans*x%mod;
		mi[x]++;
	}
	mp[id][x]++;
	cnt[x][mp[id][x]]++;
}
void divide(int id,int x){while(x!=1){change(id,vis[x]);x/=vis[x];}}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=N;++i){
		if(!vis[i])vis[i]=i,pri[++num]=i,cnt[i][0]=n,mi[i]=0;
		for(int j=1;i*pri[j]<=N&&j<=num;++j){
			vis[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		divide(i,x);
	}
	for(int i=1,id,x;i<=q;++i){
		scanf("%d%d",&id,&x);
		divide(id,x);
		printf("%d\n",ans);
	}
	return 0;
}