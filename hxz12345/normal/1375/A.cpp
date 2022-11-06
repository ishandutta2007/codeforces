#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,n,a[1001010],i;
int main(){
	Testing=read();
	for (;Testing;Testing--){
		n=read();
		for (i=1;i<=n;i++) a[i]=read();
        for (i=1;i<=n;i++){
        if ((i&1)&&(a[i]>0)) a[i]=-a[i];
        if ((i % 2==0)&&(a[i]<0)) a[i]=-a[i];
		}
        for (i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
	}
	return 0;
}