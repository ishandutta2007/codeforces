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
double lst,G,x,y,X[1010],Y[1010];
int tot,i;
void Main(){
	x=0;y=0;tot=0;
for (i=1;i<=3;i++) scanf("%lf%lf",&X[i],&Y[i]),x=max(x,X[i]),y=max(y,Y[i]);
for (i=1;i<=3;i++)
    if (Y[i]==y) tot++;
if (tot==2){
	lst=1000000000;G=0;
	for (i=1;i<=3;i++)
	   if (Y[i]==y) lst=min(lst,X[i]),G=max(G,X[i]);
	   printf("%.10lf\n",G-lst);
}else puts("0.00000");
}
int main()
{
	int Testing;
	Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}