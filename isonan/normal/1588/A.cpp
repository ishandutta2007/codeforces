#include <cstdio>

int t,n,a[101],b[101],A[210],B[210];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=0;i<=200;++i)A[i]=B[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",a+i),++A[a[i]+100];
		for(int i=1;i<=n;++i)scanf("%d",b+i),++B[b[i]+100];
		int tot=0;
		bool ok=1;
		for(int i=0,pre=-1;i<=200;++i){
			if(B[i]<0)ok=0;
			if(A[i]>B[i]){
				B[i+1]-=A[i]-B[i];
			}
			if(A[i]<B[i])ok=0;
		}
		if(!ok)puts("NO");
		else puts("YES");
	}
}