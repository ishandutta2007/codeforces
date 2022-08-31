#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#define int long long 

int head[300001],nxt[800001],b[800001],k,n,dist[9][300001],q[300001],h,t,Dis[9][9],stat[100001];
char str[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void link(int s,int t){
	push(s,t);
	push(t,s);
}
void getdis(int S,int *dis){
	for(int i=1;i<=(n<<1)+8;i++)dis[i]=n*6;
	dis[S]=0;
	h=t=0;
	q[++t]=S;
	while(h<t){
		++h;
		for(int i=head[q[h]];i;i=nxt[i])
			if(dis[b[i]]==n*6){
//				printf("%d %d\n",b[i],q[h]);
				dis[b[i]]=dis[q[h]]+1;
				q[++t]=b[i];
			}
	}
}
int set[9][256];
bool judge(int u){
//	printf("judge %d\n",u);
	for(int i=1;i<=8;i++)memset(set[i],0,sizeof set[i]);
	for(int i=1;i<=n;i++){
		if(i>u){
			for(int j=1;j<=8;j++){
				int ask=0;
				for(int k=1;k<=8;k++)
					if(dist[k][i]+1+Dis[k][j]+1==u)ask|=(1<<(k-1));
					else if(dist[k][i]+1+Dis[k][j]+1<u)ask=-1;
//				printf("%d %d %d\n",i,j,ask);
				if(~ask&&set[j][ask])return 1;
			}
		}
		if(i>=u)
			for(int j=0;j<256;j++)
				if((j|stat[i-u+1])==stat[i-u+1])set[str[i-u+1]-'a'+1][j]=1;
	}
	return 0;
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%s",&n,str+1);
	for(int i=1;i<=n;i++){
		link(i,i+n);
		if(i>1)link(i-1+n,i);
		link(i,(n<<1)+str[i]-'a'+1); 
	}
	for(int i=1;i<=8;i++){
		getdis((n<<1)+i,dist[i]);
		for(int j=1;j<=n;j++)dist[i][j]>>=1;
	}
//	for(int i=1;i<=n;i++,putchar('\n'))
//		for(int j=1;j<=8;j++)printf("%d ",dist[j][i]);
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			Dis[i][j]=n*3;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=8;j++)
			Dis[str[i]-'a'+1][j]=Dis[j][str[i]-'a'+1]=std::min(Dis[j][str[i]-'a'+1],dist[j][i]);
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=8;j++){
			stat[i]|=(1ll<<(j-1))*(dist[j][i]-Dis[j][str[i]-'a'+1]);
			assert(dist[j][i]-Dis[j][str[i]-'a'+1]<=1);
		}
//		printf("%d %d\n",i,stat[i]);
	}
	int l=0,r=std::min(n,15ll),mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d ",ans);
	for(int i=1;i<=8;i++)memset(set[i],0,sizeof set[i]);
	long long fin=0;
//	putchar('\n');
//	for(int i=1;i<=8;i++,putchar('\n'))
//		for(int j=1;j<=8;j++)
//			printf("%d ",Dis[i][j]);
	for(int i=1;i<=n;i++){
		if(i>ans){
			for(int j=1;j<=8;j++){
				int ask=0;
				for(int k=1;k<=8;k++){
					if(dist[k][i]+1+Dis[k][j]+1==ans)ask|=(1<<(k-1));
					else if(dist[k][i]+1+Dis[k][j]+1<ans)ask=-1;
//					printf("^%d %d %d %d\n",i,j,k,ask);
				}
				if(~ask)fin+=set[j][ask];
//				printf("%d %d %d %d\n",i,j,ask,fin);
			}
		}
//		printf("%d %lld\n",i,fin);
		if(i>=ans)
			for(int j=0;j<256;j++)
				if((j|stat[i-ans+1])==stat[i-ans+1])set[str[i-ans+1]-'a'+1][j]++;
	}
	printf("%lld\n",fin);
}