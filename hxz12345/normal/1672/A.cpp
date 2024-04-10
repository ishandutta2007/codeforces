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
int n,tot,i,x;
void Main(){
	n=read();tot=0;
	for (i=1;i<=n;i++) x=read(),tot+=x-1;
	if (tot&1) puts("errorgorn");
	else puts("maomao90"); 	
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}