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
long long Testing,A,B,C,sum,part;
bool flag;
int main()
{
	Testing=read();
	for (;Testing;Testing--)
	        {
	        	A=read();B=read();C=read();
	        	sum=A+B+C;flag=false;
	        	if (sum % 9==0)
	        	    { 
	        	      part=sum/9;
	        	      if ((A<part)||(B<part)||(C<part)) flag=false;
	        	      else flag=true;
					}
				if (flag) puts("YES");else puts("NO");
			}
		return 0;
}