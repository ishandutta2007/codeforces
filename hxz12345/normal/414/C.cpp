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
int E1[2001010],E2[2001010],lsh[2001010],a[2001010];
long long F1[2001010],F2[2001010];
long long tag,now,Q,x,tot,V1,V2,n,N,i,j,len,k;
void modify2(int x,int y){for (;x;x-=x&-x) E2[x]+=y;}
long long query2(int x){int ans=0;for (;x<=N;x+=x&-x) ans+=E2[x];return ans;}
int main()
{
	n=read();N=(1<<n);
	for (i=1;i<=N;i++) a[i]=read(),lsh[i]=a[i];
	sort(lsh+1,lsh+N+1);tot=unique(lsh+1,lsh+N+1)-lsh-1;
	for (i=1;i<=N;i++) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh;
	for (j=1;j<=n;j++){
		for (i=1;i<=N;i+=(1<<j)){
            len=(1<<j);F2[j]+=len*(len-1)/2;
			for (k=i;k<=i+(1<<j)-1;k++) {
				V2=query2(a[k]+1);
				F1[j]+=V2;F2[j]=F2[j]-E1[a[k]];
				
				modify2(a[k],1);
				E1[a[k]]++;
			}
		    for (k=i;k<=i+(1<<j)-1;k++) modify2(a[k],-1),E1[a[k]]--;
		}
	}
	now=F1[n];
	Q=read();
	for (;Q;Q--){
		x=read();
		now=now-F1[x]+(F2[x]-F1[x]);tag=F2[x]-F1[x]*2;
		for (i=x+1;i<=n;i++) F1[i]=F1[i]+tag;
		for (i=x;i;i--) F1[i]=-F1[i]+F2[i];
		printf("%lld\n",now);
	}
return 0;
}