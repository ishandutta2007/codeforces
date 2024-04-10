//GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
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
long long l,r,w,b[1001010],L[1001100],R[1001010],Pr[1001010],Su[1001100],pre[1001010],j,K,H[1001010],a[1001010],ans,val[1001010],mn,tot,n,i,len,now,B[1001010],sa[1001010],rk[1001010],fre[1001010],lst[1001010];
char S[1001010],TEM[1001010];
void sort(int l,int r){tot=0;
	for (int i=n;i>n-len;i--) B[++tot]=i;
	for (i=1;i<=n;i++)
	    if (sa[i]>len) B[++tot]=sa[i]-len;
	for (i=1;i<=n;i++) fre[rk[B[i]]]++;
	for (i=1;i<=max(n,(long long) 5010);i++) fre[i]=fre[i-1]+fre[i];
	for (i=n;i>=1;i--) sa[fre[rk[B[i]]]--]=B[i];
	for (i=0;i<=max(n,(long long) 5010);i++) fre[i]=0;
}void Remake(){
	for (i=1;i<=n;i++) lst[i]=rk[i];tot=0;
	for (i=1;i<=n;i++)
	    if ((lst[sa[i]]==lst[sa[i-1]])&&((lst[sa[i]+len]==lst[sa[i-1]+len]))) rk[sa[i]]=tot;
	    else rk[sa[i]]=++tot;
} 
int main()
{
	n=read();scanf("%s",S+1);scanf("%s",TEM+1);
	for (i=1;i<=n/2;i++) swap(S[i],S[n-i+1]),swap(TEM[i],TEM[n-i+1]);
	for (i=1;i<=n;i++) sa[i]=i,rk[i]=S[i];
	for (i=1;i<=n;i++) val[i]=(TEM[i]-'0');
	len=0;
	sort(1,n);Remake();
    for (len=1;len<=n;len<<=1) sort(1,n),Remake();K=0;
    for (i=1;i<=n;i++){
      	if (rk[i]==0) continue;if (K) K--;
	    while ((S[sa[rk[i]]+K]==S[sa[rk[i]-1]+K])&&(K<=n)) K++;H[rk[i]]=K;
        }
    for (i=1;i<=n;i++)
        if (val[i]==0) ans=max(ans,n-i+1);
    for (i=1;i<n;i++) a[i]=H[i+1];n--;
    w=0;
	for (i=1;i<=n;i++){
		while ((w>0)&&(a[b[w]]>a[i])){R[b[w]]=i;w--;}
		L[i]=b[w];w++;b[w]=i;
	}while (w>0) R[b[w]]=n+1,w--;
	Su[n+2]=n+2;for (i=n+1;i>=1;i--) if (val[sa[i]]==0) Su[i]=i;else Su[i]=Su[i+1];
	for (i=1;i<=n+1;i++) if (val[sa[i]]==0) Pr[i]=i;else Pr[i]=Pr[i-1];
	for (i=1;i<=n+1;i++) pre[i]=pre[i-1]+1-val[sa[i]];
	for (i=1;i<=n;i++)
	     {
	     	l=Su[L[i]+1];r=Pr[R[i]];
	     	if ((l!=n+2)&&(r!=0)&&(l<=r-1))
	     	     ans=max(ans,a[i]*(pre[r]-pre[l-1]));
		 }
printf("%lld\n",ans);
return 0;
}
//