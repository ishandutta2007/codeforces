#include <cstdio>

int n,a[1000001],f[1000010],stk[1000001],top;
long long S[1000001];
bool comp(int x,int y,int z){return 1ll*(S[z]-S[x])*(z-y)>=1ll*(S[z]-S[y])*(z-x);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),S[i]=S[i-1]+a[i];
	for(int i=n;~i;i--){
		while(top>1&&comp(i,stk[top],stk[top-1]))--top;
		if(i<n)f[i+1]=top?stk[top]:i+1;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++){
		double ans=((double)(S[f[i]]-S[i-1]))/((double)(f[i]-i+1));
		for(int j=i;j<=f[i];j++)printf("%.9lf\n",ans);
		i=f[i];
	}
}