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
struct node{
	long long x,y;
} e[1001010];
long long ans,n,i,w,q[1001010];
bool cmp(node a,node b){return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y)));};
int main()
{
	n=read();
	if (n==1){puts("0");return 0;}
	for (i=1;i<=n;i++){
		e[i].x=read();e[i].y=read();
		e[i].y-=e[i].x*e[i].x;
	}
	sort(e+1,e+n+1,cmp);
	q[1]=1;q[2]=2;w=2;
	for (i=3;i<=n;i++){
		while ((w>1)&&((e[i].y-e[q[w]].y)*(e[q[w]].x-e[q[w-1]].x)>(e[i].x-e[q[w]].x)*(e[q[w]].y-e[q[w-1]].y))) w--;
		w++;q[w]=i;
	}
	if (e[q[1]].x!=e[q[2]].x) ans++;
	for (i=2;i<w;i++)
	    if ((e[q[i]].y-e[q[i+1]].y)*(e[q[i-1]].x-e[q[i]].x)!=(e[q[i]].x-e[q[i+1]].x)*(e[q[i-1]].y-e[q[i]].y)) 
	        ans++;
	printf("%lld\n",ans);
    return 0;
}