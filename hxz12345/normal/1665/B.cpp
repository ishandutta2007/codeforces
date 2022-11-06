// Problem: B. Array Cloning Technique
// Contest: Codeforces - Codeforces Round #781 (Div. 2)
// URL: https://codeforces.com/contest/1665/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
map<long long,long long>G;
long long y,x,ans,aa,n,i,a[1001010];
void Main(){
  n=read();G.clear();y=0;
  for (i=1;i<=n;i++) {
  	x=read();y=max(y,++G[x]);
  }ans=0;aa=y;
  while (1){
  	if (aa==n) break;ans++;
  	if (aa*2<=n) {
  		ans+=aa;aa=aa*2;
	  }else {
	  	ans+=n-aa;break;
	  }
  }
  printf("%lld\n",ans);
}
int main()
{	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}