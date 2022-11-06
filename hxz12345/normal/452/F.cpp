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
int n,tot,a[1001010],tag[1001010],i,j;
void Main(){
	tot=100000000/n;
    for (i=1;i<=n;i++){
			for (j=max(1,i-tot);j<i;j++)
			    if ((a[i]+a[j]) % 2==0)
			        if ((tag[(a[i]+a[j])/2]>j)&&(tag[(a[i]+a[j])/2]<i)){
			        	puts("YES");return ;
					}
			    
		}
	for (i=1;i<=n;i++){//a[j]-(a[i]-a[j])  2*a[j]-a[i]
			for (j=max(1,i-tot);j<i;j++)
			        if ((2*a[j]-a[i]>0)&&(2*a[j]-a[i]<=n))
			            if (tag[2*a[j]-a[i]]<j){
			            	puts("YES");return ;
						}
			    
		}
	for (i=1;i<=n;i++){//a[j] a[i] a[i]+a[i]-a[j]
			for (j=max(1,i-tot);j<i;j++)
			        if ((2*a[i]-a[j]<=n)&&(2*a[i]-a[j]>=1))
			            if (tag[2*a[i]-a[j]]>i){
			            	puts("YES");return ;
						}
		}
	puts("NO");
}
int main()
{
	for (int Testing=1;Testing;Testing--){
		n=read();
		for (i=1;i<=n;i++) a[i]=read(),tag[a[i]]=i;
		Main();
	}
return 0;
}