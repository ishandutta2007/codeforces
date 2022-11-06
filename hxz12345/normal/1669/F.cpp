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
long long n,G1,G2,tot,r,i,a[1001010];
void Main(){
n=read();
for (i=1;i<=n;i++) a[i]=read();
r=n;G1=G2=0;tot=0;
for (i=1;i<=n;i++){
	G1+=a[i];
	while ((r>=i)&&(G2<G1)) G2+=a[r],r--;
	if ((G1==G2)&&(r>=i)) tot=max(tot,n-r+i);
}
printf("%lld\n",tot);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}