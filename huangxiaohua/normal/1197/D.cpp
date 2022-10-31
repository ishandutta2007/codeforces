#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,n1;
ll a[300500],f[300500],f2[300500],tmp,pre,d,res;

int main(){
	scanf("%d%d%lld",&n,&m,&d);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		tmp=d;pre=0;
		for(j=0;j<m;j++){
			if(i+j>n){break;}
			pre+=a[i+j];tmp=max(tmp,pre);
		}
		f[i]=pre-d;f2[i]=tmp-d;
		res=max(res,f2[i]);
	}
	for(t=1;t<=m;t++){
		tmp=0;pre=0;
		for(i=t;i<=n;i+=m){
			pre+=f[i];
			res=max(res,pre-tmp+f2[i+m]);
			tmp=min(tmp,pre);
		}
	}
	printf("%lld",res);
}