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
long long n,C,pre[1001010],a[1001010],i,j,fre[1001010];
bool flag;
void Main(){
	n=read();C=read();
	for (i=1;i<=n;i++) {a[i]=read();fre[a[i]]=1;}
	pre[0]=0;
	for (i=1;i<=C;i++) pre[i]=pre[i-1]+fre[i];
	flag=false;
	for (i=1;i<=C;i++)
	   for (j=1;j<=C/i;j++)
	       if ((fre[i]==1)&&(fre[j]==0)&&(pre[min(i*(j+1)-1,C)]-pre[i*j-1]>0))
	       flag=true;
	
	for (i=1;i<=n;i++) fre[a[i]]=0;
	
    if (flag==false){
    	puts("Yes");return ;
	}else {
		puts("No");return ;
	}
}
int main()
{
	int Testing;
	Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}