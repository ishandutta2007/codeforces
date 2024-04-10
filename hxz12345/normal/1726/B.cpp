#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
//5 3
//
int n,m,a[1001010],i,x,y;
void Main(){
	n=read();m=read();
	if (m % n==0) {
		puts("Yes");
		for (i=1;i<=n;i++) printf("%d ",m/n);
		puts("");
		return ;
	}
	if (m<n) {puts("No");return ;}
	x=m/n;y=m % n;
    for (i=1;i<=n;i++) a[i]=x;
    if ((n % 2==1)){
    	puts("Yes");
		for (i=1;i<n;i++) printf("%d ",a[i]);
    	printf("%d\n",x+y);
    	puts("");
	    return ;
	    }
	if ((n % 2==0)&&(m % 2==0)){
		puts("Yes");
		for (i=1;i<=n-2;i++) printf("%d ",a[i]);
		printf("%d %d\n",x+(y/2),x+(y/2));
		puts("");
		return ;
	}
	puts("No");
	//1 1 1 
	//m
	return ;
}
int main(){
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}