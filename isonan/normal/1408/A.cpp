#include <cstdio>

int T,n,a[101],b[101],c[101],p[101];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)scanf("%d",b+i);
		for(int i=1;i<=n;i++)scanf("%d",c+i);
		for(int i=1;i<n;i++){
			if(a[i]!=p[i-1])p[i]=a[i];
			if(b[i]!=p[i-1])p[i]=b[i];
			if(c[i]!=p[i-1])p[i]=c[i];
		}
		if(a[n]!=p[1]&&a[n]!=p[n-1])p[n]=a[n];
		if(b[n]!=p[1]&&b[n]!=p[n-1])p[n]=b[n];
		if(c[n]!=p[1]&&c[n]!=p[n-1])p[n]=c[n];
		for(int i=1;i<=n;i++)printf("%d ",p[i]);putchar('\n');
	}
}