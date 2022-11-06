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
int n,i,a[1001010],f1,f2,f3;
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	f1=f2=f3=0;
	for (i=1;i<=n;i++)
	   if (a[i]==0) f1=1;else if (a[i]==1) f2=1;
	for (i=2;i<=n;i++)
	    if (a[i]==a[i-1]+1){
	    	f3=1;break;
		}
	if (f1&&f2) {puts("NO");return ;}
	
	if (f2&&f3){puts("NO");return ;}
	puts("YES");
return ;
}
int main()
{
 int Testing=read();
 for (;Testing;Testing--) Main();
 return 0;
}