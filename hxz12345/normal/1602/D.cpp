#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
bool flag;
long long l,r,mid,tag,nxt[1001010],pre[1001010],prew[1001010],w,c[1001010],n,i,a[1001010],b[1001010],t,f1[1001010],f[1001010];
void modify(long long x,long long y){for (;x<=n+1;x+=x&-x) nxt[x]+=y;}
long long query(long long x){long long ans=0;for (;x;x-=x&-x) ans+=nxt[x];return ans;}
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();
	for (i=0;i<=n;i++) f[i]=1e11;
	f[n]=0;t=1;w=1;f1[1]=n;
	while (t<=w){
		if (f1[t]==0){
			printf("%lld\n",f[0]);
	        w=1;c[1]=0;
	        for (i=0;i!=n;i=pre[i]) c[++w]=pre[i]-prew[i];
	        for (i=1;i<w;i++) printf("%lld ",c[w-i+1]);
	        return 0;
		    }
		i=-1;l=f1[t]-a[f1[t]];r=f1[t];
		
		while (l<=r){
			mid=(l+r)/2;
			if (query(f1[t]+1)-query(mid)!=f1[t]-mid+1){i=mid;l=mid+1;}else r=mid-1;
		}
		while (i>=f1[t]-a[f1[t]]){
			if (f[i+b[i]]==1e11){
			f[i+b[i]]=f[f1[t]]+1;w++;f1[w]=i+b[i];
			pre[i+b[i]]=f1[t];prew[i+b[i]]=f1[t]-i;}
			modify(i+1,1);
			l=f1[t]-a[f1[t]];r=i-1;tag=-1;
			while (l<=r){
			mid=(l+r)/2;//i-1~mid
			if (query(i)-query(mid)!=i-1-mid+1){tag=mid;l=mid+1;}else r=mid-1;
		}i=tag;
		}
		t++;
	}
	if (f[0]==1e11){puts("-1");return 0;}
    return 0;
}