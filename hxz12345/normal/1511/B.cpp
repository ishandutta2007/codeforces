//aa
#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long Testing,n,sum,i,x,A,B,C,Pa,Pb,Pc;
//999900
//100000
//100
int main()
{
	Testing=read();
	for (;Testing;Testing--)
	        {
	        	A=read();B=read();C=read();
	        	Pc=1;
	        	for (i=1;i<C;i++) Pc*=10;
	        	A-=C;B-=C;
	        	Pa=1;Pb=9;
	        	for (i=1;i<=A;i++) Pa=Pa*10;
	            for (i=1;i<=B;i++) Pb=Pb*10+9;
	            printf("%lld %lld\n",Pa*Pc,Pb*Pc);
			}
		return 0;
}