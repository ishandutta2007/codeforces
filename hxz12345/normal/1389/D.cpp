#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long GG,val,dif,now1,i,ans,lft,rit,spd,now,tot,n,K,a[1001010],b[1001001],c[1001010],d[1001010],L,R;
int main() {
	int Testing=read();
	for (;Testing;Testing--){
		n=read();K=read();
		for (i=1;i<=1;i++) a[i]=read(),b[i]=read();
		for (i=2;i<=n;i++) a[i]=a[1],b[i]=b[1];
		for (i=1;i<=1;i++) c[i]=read(),d[i]=read();
		for (i=2;i<=n;i++) c[i]=c[1],d[i]=d[1];
		ans=0;tot=0;
		for (i=1;i<=n;i++){
			   L=max(a[i],c[i]);R=min(b[i],d[i]);
		       if (L<=R) ans+=R-L;
		}
		if (ans>=K) {
			puts("0");continue;
		}
		tot=0;
		for (i=1;i<=n;i++){
			L=max(a[i],c[i]);R=min(b[i],d[i]);
			if (L<=R){
				lft=min(a[i],c[i]);rit=max(b[i],d[i]);
				now=L-lft+rit-R;
				if (ans+now>=K){
					tot+=K-ans;ans=K;break;
				}
				ans=ans+now;tot+=now;
			}
		}
	    if (ans>=K){
	    	printf("%lld\n",tot);continue;
		}
		GG=0;
		for (i=1;i<=n;i++){
			L=max(a[i],c[i]);R=min(b[i],d[i]);
			if (L>R){
			     val=max(b[i],d[i])-min(a[i],c[i]);
			     spd=L-R;
			     dif=K-ans;
			     if (val>dif){
			     	now=spd+dif;now1=dif*2;
			     	if (now<=now1){
			     		tot+=now;ans=K;
					 }
				 }
				 else{
				 	now=spd+val;now1=val*2;
				 	if (now<=now1){
				 		tot+=now;ans+=val;
					 }
				 }
			}
		}
		if (ans==0){
			tot=1000000000000000000;
			for (i=1;i<=n;i++)
			     {
			     	spd=max(a[i],c[i])-min(b[i],d[i]);
			     	now=spd;
			     	val=max(b[i],d[i])-min(a[i],c[i]);
			        if (ans+val<K) tot=min(tot,spd+val+(K-val)*2);
			        else tot=min(tot,spd+K);
				 }
				printf("%lld\n",tot);
		}
		else{
		tot=tot+(K-ans)*2;
		printf("%lld\n",tot);
	}
		}
    return 0;
}