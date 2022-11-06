#include<bits/stdc++.h>
using namespace std;
inline int read()
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long f[101000][5],a[101000],c[101000];
int n,i;
string s;
long long ans;
//abcdefghijklmnopqrstuvwxyz
//1  4   8         18 
int main()
{
	n=read();
	cin>>s;
	for (i=1;i<=n;i++)
	     {
	     	a[i]=s[i-1]-'a'+1;
		 }
	for (i=1;i<=n;i++) c[i]=read();
	for (i=1;i<=n;i++)
	      {
	      	if (a[i]==8) 
			     {
			     f[i][2]=f[i-1][2];f[i][3]=f[i-1][3];f[i][4]=f[i-1][4];
				 f[i][1]=min(f[i-1][0],f[i-1][1]);
				 f[i][0]=f[i-1][0]+c[i];
				 }
			else if (a[i]==1)
		            {
		            	f[i][2]=min(f[i-1][1],f[i-1][2]);
		            	f[i][1]=f[i-1][1]+c[i];
		            	f[i][0]=f[i-1][0];
		            	f[i][3]=f[i-1][3];f[i][4]=f[i-1][4];
					}
			else if (a[i]==18)
			       {
			       	f[i][3]=min(f[i-1][2],f[i-1][3]);
			       	f[i][2]=f[i-1][2]+c[i];
			       	f[i][1]=f[i-1][1];
			       	f[i][0]=f[i-1][0];
			       	f[i][4]=f[i-1][4];
				   }
		   else if (a[i]==4)
		           {
		           	  f[i][4]=min(f[i-1][3],f[i-1][4]);
		           	  f[i][3]=f[i-1][3]+c[i];
		           	  f[i][2]=f[i-1][2];
		           	  f[i][1]=f[i-1][1];
		           	  f[i][0]=f[i-1][0];
				   }
		else
		     {
		     	f[i][1]=f[i-1][1];f[i][2]=f[i-1][2];f[i][3]=f[i-1][3];f[i][4]=f[i-1][4];f[i][0]=f[i-1][0];
			 }
	}
ans=1000000000000000000;
for (i=0;i<4;i++) ans=min(ans,f[n][i]);
printf("%lld\n",ans);
return 0;
}