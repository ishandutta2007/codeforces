#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[400500];
ll res=1e18,b[400500],res2,pre[400500],pre2[400500],tmp;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);res2+=k;
		if(!b[k]){a[++n]=k;}b[k]++;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=400005;i++){
		pre[i]=pre[i-1]+b[i]*i;pre2[i]=pre2[i-1]+b[i];
	}
	for(i=1;i<=n;i++){
		tmp=0;
		for(j=0;j<=200005;j+=a[i]){
			tmp+=(pre[j+a[i]-1]-pre[j])-(pre2[j+a[i]-1]-pre2[j])*j;
		}
		res=min(res,tmp);
	}
	printf("%lld",res2-res);
}