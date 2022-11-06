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
long long cnt,n,d[1001010],deg[1001010],a[1001010],b[1001010],x,y,i,Answer[1001010];
void add(int x,int y){
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void sc(int x,int fa,long long val){
   if (val&1) Answer[x]=-deg[x];else Answer[x]=deg[x];
   for (int i=d[x];i;i=b[i])
       if (a[i]!=fa) 
           sc(a[i],x,val+1);
}
void Main(){
	n=read();cnt=0;
	for (i=1;i<=n;i++) d[i]=deg[i]=0;
	for (i=1;i<n;i++){
		x=read();y=read();add(x,y);add(y,x);deg[x]++;deg[y]++;
	}
	sc(1,0,0);
	for (i=1;i<=n;i++) printf("%lld ",Answer[i]);
	puts("");
return ;
}
int main()
{
 int Testing=read();
 for (;Testing;Testing--) Main();
 return 0;
}