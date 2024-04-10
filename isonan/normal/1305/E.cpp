#include <cstdio>

int n,m,a[5001],cont[5001];
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(i+j<=n)++ans,++cont[i+j];
	if(ans<m){
		puts("-1");
		return 0;
	}
	int inf=1000000000;
	for(int i=n;i;i--){
		if(ans-cont[i]>m)a[i]=inf-((n<<1)+1)*(n-i),ans-=cont[i];
		else{
			while(ans>m){
				a[i]+=(a[i]%2)?1:2;
				--ans;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
}