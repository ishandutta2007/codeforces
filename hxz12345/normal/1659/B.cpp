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
char S[1001010];
int n,K,i;
long long a[1001010],b[1001010];
void Main(){
  n=read();K=read();
  scanf("%s",S+1);
  for (i=1;i<=n;i++) a[i]=S[i]-'0';
  for (i=1;i<=n;i++) b[i]=0;
  if (K&1) for (i=1;i<=n;i++) a[i]=1-a[i];
  for (i=1;i<n;i++)
      if ((a[i]==0)&&(K>0))
           K--,a[i]=1,b[i]=1;
  b[n]=K;
  if (K&1) a[n]=1-a[n];
  for (i=1;i<=n;i++) printf("%d",a[i]);
  puts("");
  for (i=1;i<=n;i++)
      printf("%lld ",b[i]);
    puts("");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}