#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
//1 2 2 3 6
//
long long exist,a[1001010],GG,tag,n,i,ans;
void Main(){
  n=read();
  for (i=1;i<=n;i++) a[i]=read();tag=0;GG=0;
  if (n==3){
  	if (a[2]&1) puts("-1");
  	else printf("%lld\n",a[2]/2);
  	return ;
  }
  exist=0;
  for (i=2;i<n;i++) 
     if (a[i]>=2)
        exist=1;
  for (i=2;i<=n-1;i++) tag+=a[i]&1,GG+=a[i];
  if ((tag>0)&&(exist==0)) puts("-1");
  else printf("%lld\n",(tag+GG)/2);
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}