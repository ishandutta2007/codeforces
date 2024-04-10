#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,m,a[100500],mx;
double res,k,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);mx=0;res=0,tmp=1;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=i){mx=i;}
		}
		if(!mx){tmp=0;
		}
		for(i=1;i<=m;i++){
			scanf("%d%lf",&j,&k);
			if(j>=mx){tmp*=(1-k);}
		}
		printf("%.6lf\n",1-tmp);
	}
}