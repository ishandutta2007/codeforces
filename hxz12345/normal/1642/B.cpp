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
long long Testing,ans,i,a[1001010],n;
void Main(){
n=read();
for (i=1;i<=n;i++) a[i]=read();
sort(a+1,a+n+1);ans=0;
for (i=1;i<=n;i++)
    if (a[i]!=a[i-1]) ans++;
for (i=1;i<=n;i++) printf("%lld ",max(ans,i));
puts("");
}
int main()
{
	int Testing;
	Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}