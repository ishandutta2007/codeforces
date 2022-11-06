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
long long n,a[1001010],G1,G2,T1,T2,i;
void Main(){
	n=read();
	T1=0;T2=0;G1=0;G2=0;
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) 
	    if (i&1) G1+=a[i]&1,T2++;
	    else G2+=a[i]&1,T1++;
    if ((G1!=0)&&(G1!=T2)) {
    	puts("NO");return ;
	}
	
    if ((G2!=0)&&(G2!=T1)) {
    	puts("NO");return ;
	}puts("YES");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}