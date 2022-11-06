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
long long i,x,K,ans,l,r,mid,n,cnt,a[1001010],b[1001010],d[1001010],siz[1001010],tag,deg[1001010];
void add(int x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa){
	siz[x]=0;
	for (int i=d[x];i;i=b[i])
	    if (a[i]!=fa) sc(a[i],x),siz[x]++;
	if (siz[x]) tag++;
}
bool cmp(long long x,long long y){return x>y;}
bool check(long long x){
	long long now=0;
	for (int i=1;i<=n;i++) {
		if (siz[i]<=0) break;
		now+=max((long long) 0,siz[i]-x);
	}
	return now<=x;
}
void Main(){
	n=read();
	cnt=0;
	for (i=1;i<=n;i++) d[i]=0,deg[i]=0;tag=0;K=0;
	for (i=2;i<=n;i++) x=read(),add(x,i),add(i,x);
	sc(1,0);siz[n+1]=1;tag++;
	sort(siz+1,siz+n+2,cmp);
    K=tag;
    for (i=1;i<=tag;i++) siz[i]-=(tag-i+1);
    sort(siz+1,siz+n+2,cmp);
    l=0;r=n;ans=n+1;
    while (l<=r){
    	mid=(l+r)>>1;
    	if (check(mid)){
    		ans=mid;r=mid-1;
		}else l=mid+1;
	}	printf("%lld\n",K+ans);
}
int main()
{	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}