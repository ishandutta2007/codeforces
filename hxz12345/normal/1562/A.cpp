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
//a % b=x
//a=t*b+x
//a-x=t*b
//r-x=t*l
//
long long Testing,lft,rit,ans,L,R;
int main()
{
	for (Testing=read();Testing;Testing--)
	    {
	    	L=read();R=read();ans=0;
	    	ans=R % L;
	    	if (((R/2+1)>=L)) 
			   ans=max(ans,R % (R/2+1));
	    	printf("%lld\n",ans);
	    /*	for (lft=L;lft<=R;lft++)
	    	   for (rit=lft;rit<=R;rit++)
	    	      if (rit % lft>ans)
	    	        ans=rit % lft;
	    	for (lft=L;lft<=R;lft++)
	    	   for (rit=lft;rit<=R;rit++)
	    	      if (rit % lft==ans)
	    	        cout<<"Answer:"<<lft<<" "<<rit<<endl;*/
		}
	return 0;
}