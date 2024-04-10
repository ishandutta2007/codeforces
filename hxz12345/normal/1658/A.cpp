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
long long n,ans,now,i;
char S[1001010];
void Main(){
	n=read();
	scanf("%s",S+1);ans=0;now=100;
	for (i=1;i<=n;i++) 
	    if (S[i]=='1') now++;
	else ans+=max(2-now,(long long)0),now=0;
    printf("%lld\n",ans);	
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
 return 0;
}