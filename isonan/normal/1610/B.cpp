#include <cstdio>

int t,a[200001],b[200001],top,n;
bool Try(int x){
	top=0;
	for(int i=1;i<=n;++i)if(a[i]!=x)b[++top]=a[i];
	for(int i=1;i<=top;++i)
		if(b[i]!=b[top-i+1])return 0;
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		// int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		bool out=0;
		for(int i=1;i<=n;++i)
			if(a[i]!=a[n-i+1]){
				if(Try(a[i])||Try(a[n-i+1]))puts("YES");
				else puts("NO");
				out=1;
				break;
			}
		if(!out)puts("YES");
	}
}