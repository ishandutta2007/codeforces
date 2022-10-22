#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[210000],Ans[210000];
ll suf[210000];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if (i+a[i]-1>n){
			puts("-1");
			return 0;
		}
	}
	for (int i=m;i>=1;i--) suf[i]=suf[i+1]+a[i];
	if (suf[1]<n){
		puts("-1");
		return 0;
	}
	int mx=0;
	for (int i=1;i<=m;i++){
		if (i<=n-suf[i]+1&&n-suf[i]+1<=mx+1){
			for (int j=1;j<i;j++) Ans[j]=j;
			Ans[i]=n-suf[i]+1;
			for (int j=i;j<m;j++) Ans[j+1]=Ans[j]+a[j];
			for (int j=1;j<m;j++) printf("%d ",Ans[j]);
			printf("%d\n",Ans[m]);
			return 0;
		}
		mx=max(mx,i+a[i]-1);
	}
	puts("-1");
	return 0;
}