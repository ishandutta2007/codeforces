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
int n,x,mn,mx,i,id,id1;
void Main(){
	n=read();mn=2e9;mx=0;
	for (i=1;i<=n;i++){
	  x=read();	
	  if (x>mx) mx=x,id=i;
	  if (x<mn) mn=x,id1=i;
	}
	printf("%d %d\n",id1,id);
return ;
}
int main()
{
 int Testing=read();
 for (;Testing;Testing--) Main();
 return 0;
}