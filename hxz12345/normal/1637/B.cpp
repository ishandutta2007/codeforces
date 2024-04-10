#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long i,a[1001010],lft,rit,n,ans;
long long solve(long long l,long long r){
	long long ans=0;
	for (int i=l;i<=r;i++) ans+=a[i]==0;
	return ans+r-l+1;
}
void Main(){
  n=read();
  for (i=1;i<=n;i++) a[i]=read();ans=0;
  for(lft=1;lft<=n;lft++)
     for (rit=lft;rit<=n;rit++)
         ans+=solve(lft,rit);
   printf("%lld\n",ans);
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}