#include <cstdio>
#include <random>
#include <cstring>
#include <algorithm>

std::mt19937 rnd(19260817);
int t,n,a[200010];
long long S1[200010],S2[200010],tem[200010];
long long key[200010];
int size[200010];
int lson[200010],rson[200010],pri[200010];
void pushup(int x){
	size[x]=size[lson[x]]+size[rson[x]]+1;
}
void split(int now,int &x,int &y,long long v){
	if(!now)x=y=0;
	else{
		if(key[now]<=v)x=now,split(rson[now],rson[now],y,v);
		else y=now,split(lson[now],x,lson[now],v);
		pushup(now);
	}
}
void split2(int now,int &x,int &y,long long v){
	if(!now)x=y=0;
	else{
		if(size[lson[now]]+1<=v)x=now,split2(rson[now],rson[now],y,v-size[lson[now]]-1);
		else y=now,split2(lson[now],x,lson[now],v);
		pushup(now);
	}
}
int merge(int a,int b){
	if(!a||!b)return a|b;
	if(pri[a]<pri[b]){
		rson[a]=merge(rson[a],b);
		pushup(a);
		return a;
	}
	else{
		lson[b]=merge(a,lson[b]);
		pushup(b);
		return b;
	}
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=200000;++i)pri[i]=rnd();
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		std::reverse(a+1,a+n+1);
		long long ans=0;
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k){
				long long t1=0;
				if(j)t1-=a[1];
				if(k)t1+=a[n];
				int l=j+1,r=n-k;
//				printf("%d %d %d %d\n",j,k,l,r);
				memset(S1,0,(n+3)<<3);
				memset(S2,0,(n+3)<<3);
				memset(tem,0,(n+3)<<3);
				for(int i=l;i<=r;++i){
					tem[i]=tem[i-1]+a[i];
					S1[i]=tem[i];
				}
				for(int i=l;i<=r;++i)S2[i]=tem[r]-tem[i-1];
				for(int i=l;i<=r;++i){
					tem[i]=a[i]-tem[i-1];
					S2[i+1]-=tem[i];
					S1[i]-=tem[i];
				}
				for(int i=l-1;i<=r;++i)S1[i]+=t1;
				int rt[2]={0};
				for(int i=l;i<=r+1;++i){
					if(i>=r&&k)continue;
					lson[i]=rson[i]=0;
//					printf("Add %d\n",i);
					key[i]=S2[i];
					pushup(i);
					int t1,t2;
					split(rt[i&1],t1,t2,key[i]);
					rt[i&1]=merge(t1,merge(i,t2));
				}
//				printf("**%d %d\n",S1[2],S2[5]);
				for(int i=l-1;i<=r;++i){
					if(i>=l){
						if(!(i>=r&&k)){
//							printf("Del %d\n",i);
							int t1,t2,t3;
							split(rt[i&1],t1,t2,S2[i]);
							split2(t1,t1,t3,size[t1]-1);
							rt[i&1]=merge(t1,t2);
						}
					}
					if(i<=l&&j)continue;
					int t1,t2;
					split(rt[(i&1)^1],t1,t2,S1[i]-1);
//					printf("%d %d\n",i,size[t1]);
					ans+=size[t1];
					rt[(i&1)^1]=merge(t1,t2);
				}
//				printf("%d\n",ans);
			}
		for(int i=1;i<=n;++i)tem[i]=tem[i-1]+a[i];
		for(int i=1;i<=n;++i){
			if(i>1&&n-i>1){
				if(tem[i]<tem[n]-tem[i])++ans;
			}
		}
		printf("%d\n",ans%998244353);
	}
}