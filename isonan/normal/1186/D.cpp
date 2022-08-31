#include <cstdio>
#include <cmath>

int n,b[100001];
long long ans;
double a[100001];
bool cangoup[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",a+i);
		b[i]=(int)floor(a[i]);
		ans+=b[i];
		if((int)ceil(a[i])!=b[i])cangoup[i]=1;
	}
	for(int i=1;ans;i++){
		if(cangoup[i])++b[i],++ans;
	}
	for(int i=1;i<=n;i++)printf("%d\n",b[i]);
}