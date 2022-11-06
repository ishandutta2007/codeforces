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
string S;
long long len,x,K,Testing,lft,rit,ans,L,R,fre[1001010],n,i;
bool flag;
bool check(long long x)
{
	long long i;
	for (i=2;i<=sqrt(x);i++)   if ( x % i==0) return true;
	return false;
}
int main()
{
	for (Testing=read();Testing;Testing--)
	    {
	    	K=read();
	    	for (i=0;i<=9;i++) fre[i]=0;
	    	cin>>S;
	    	for (i=0;i<K;i++) fre[S[i]-'0']++;
	    	if (fre[1]) puts("1"),puts("1");
			else if (fre[4]) puts("1"),puts("4");
			else if (fre[6]) puts("1"),puts("6");
			else if (fre[8]) puts("1"),puts("8");
			else if (fre[9]) puts("1"),puts("9");
			else
			    {
			    	   // 2 3 5 7
			    	   flag=false;x=1e9;
			    	   for (lft=1;lft<=K;lft++)
			    	      {
						  if (flag) break;
			    	      for (rit=lft+1;rit<=K;rit++)
			    	         if (check((S[lft-1]-'0')*10+(S[rit-1]-'0')))
			    	               {
								    x=min(x,(long long)((S[lft-1]-'0')*10+(S[rit-1]-'0')));
											    	             	break;
								}
			    	    }
					puts("2");
					printf("%lld\n",x);
			    	         
				 } 
		}
	return 0;
}