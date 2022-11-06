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
int j,n,a[1001010],l,num,i,V3,len,V1,V2,b[1001010];
void Main(){
	n=read();len=n;V3=0;
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for (i=n-1;i>=1;i--){
		int V1=0;
		if (V3>0) V2=V3-1;else V2=0;
		if ((V3)&&(len)) b[++V1]=a[1];
		for (j=1;j<len;j++)
		    if (a[j]!=a[j+1]) b[++V1]=a[j+1]-a[j];
		    else V2++;
		sort(b+1,b+V1+1);len=0,V3=V2;
		for (j=1;j<=V1;j++) a[++len]=b[j];
	}
	if (len==0) puts("0");
	else printf("%d\n",a[1]);
	return ;
}
int main()
{
	int Testing;Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}