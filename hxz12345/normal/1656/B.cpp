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
map<int,bool> exist;
int a[1001010],n,K,i;bool flag;
void Main(){
	n=read();K=read();exist.clear();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);flag=false;
	for (i=1;i<=n;i++) {
		exist[a[i]]=true;
		if (exist[a[i]-K]) flag=true;
		if (exist[a[i]+K]) flag=true;
	}
	if (flag) puts("YES");
	else puts("NO");
return ;
}
int main()
{
 int Testing=read();
 for (;Testing;Testing--) Main();
 return 0;
}