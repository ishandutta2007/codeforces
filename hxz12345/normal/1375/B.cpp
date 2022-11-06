#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,a[1010][1010],n,m,i,j;
bool flag;
int main(){
	Testing=read();
	for (;Testing;Testing--){
		n=read();m=read();
		for (i=1;i<=n;i++)
		   for (j=1;j<=m;j++)
		      a[i][j]=read();
	    flag=((a[1][1]<=2)&&(a[n][m]<=2)&&(a[n][1]<=2)&&(a[1][m]<=2));
	    for (i=1;i<=n;i++)
	        if ((a[i][1]>3)||(a[i][m]>3)) flag=false;
	    for (i=1;i<=m;i++)
	        if ((a[1][i]>3)||(a[n][i]>3)) flag=false;
	    for (i=1;i<=n;i++)
	       for (j=1;j<=m;j++)
	           if (a[i][j]>4) flag=false;
	    if (flag==false) printf("NO\n");
	    else{
	    	printf("YES\n");
	    	for (i=1;i<=n;i++) for (j=1;j<=m;j++) a[i][j]=4;
	    	for (i=1;i<=n;i++) a[i][1]=a[i][m]=3;
	    for (i=1;i<=m;i++) a[1][i]=a[n][i]=3;a[1][1]=2;a[n][m]=2;a[n][1]=2;a[1][m]=2;
	    for (i=1;i<=n;i++)
	        {
	        	for (j=1;j<=m;j++)
	        	   printf("%d ",a[i][j]);
	        	puts("");
			}
		}
	}
	return 0;
}