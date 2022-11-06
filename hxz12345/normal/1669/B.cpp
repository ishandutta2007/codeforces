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
map<long long ,long long> mp;
long long n,i,a[1001010];
void Main(){
n=read();mp.clear();
for (i=1;i<=n;i++) a[i]=read();
for (i=1;i<=n;i++){
	mp[a[i]]++;
	if (mp[a[i]]>=3) {
		printf("%lld\n",a[i]);
		return ;
	}
}
puts("-1");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}