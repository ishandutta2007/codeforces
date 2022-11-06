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
long long Testing,n,i;
bool flag;
string s;
//1111 15

//11111 63
//3
int main()
{
	cin>>Testing;
	//i+1<=n/2
	//
	for (;Testing;Testing--)
	   { 
	   cin>>n;
	   cin>>s;flag=false;
	   for (i=1;i<=n;i++)
	      if (s[i-1]=='0')     
	          {
	          	flag=true;
	          	   if (i>(n/2))
	          	      printf("1 %lld 1 %lld\n",i,i-1);
	          	   else printf("%lld %lld %lld %lld\n",i,n,i+1,n);
				break;
			  }
	   if (flag==false) printf("1 %lld 2 %lld\n",n-1,n);
	   }
	return 0;
}