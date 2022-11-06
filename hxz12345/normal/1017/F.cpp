#include<stdio.h>
#include<bitset>
using namespace std;
unsigned pre,act,act1,rel,ans,j,len,n,A,B,C,D,i;
bitset<100000001> vis;
unsigned Func(unsigned x)
{
	return A*x*x*x+B*x*x+C*x+D;
}
unsigned ask(unsigned x)
{
	unsigned ans=0,y=x;
	for (;y<=n;) 
	   {
	   ans=ans+n/y;
	   if (y>n/x) return ans*Func(x);
	   y*=x;
       }
	return ans*Func(x);
}
int main()
{
	//5 7 11 13 17 19 23 25
	//
	scanf("%u%u%u%u%u",&n,&A,&B,&C,&D);
	ans=ask(2)+ask(3);
	//
	for (i=1;i<=n/3;i++)
	     if (vis[i]==false)
	        { 
	        if (i % 2==1) act=(i/2)*6+5;
	        else act=(i/2)*6+1;
	        if (act>n) break;
	        ans=ans+ask(act);
	        for (j=i;j;j++)
	               {
	               	 if (j % 2==1) act1=(j/2)*6+5;
	                 else act1=(j/2)*6+1;
	                 if (act1>n) break;
	                 if (act>n/act1) break;
	                 rel=act*act1;
	                 if (rel % 6==1)
	                    {
	                    	pre=(rel-1)/6*2;
	                    	vis[pre]=true;
						}
					else
					     {
					     	pre=(rel-5)/6*2+1;
					     	vis[pre]=true;
						 }
				   }
			}
	printf("%u\n",ans);
	return 0;
}