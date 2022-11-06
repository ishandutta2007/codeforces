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
map<long long,long long > V;
long long a[1001010],sum,n,i,G,G1;
bool flag;
bool solve(long long x){
	if ((V[x]>0)&&(V.find(x)!=V.end())){V[x]--;return true;}
    if (x==1) return false;
    return solve(x/2)&&solve((x+1)/2);
}
void Main(){
    n=read();V.clear();sum=0;
    for (i=1;i<=n;i++) a[i]=read(),V[a[i]]++,sum+=a[i];
    if (solve(sum)) puts("YES");else puts("NO"); 
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}