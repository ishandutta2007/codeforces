#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[100500],sb,sb2;
ll p[150]={1},res;
int chk(int k){
	int res=1;
	while(1){
		if(k%m){break;}
		k/=m;res++;
	}
	return res;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		res=0;
		sb=666666;sb2=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			//printf("%d\n",chk(a[i]));
			if(chk(a[i])<sb){sb2=i;sb=chk(a[i]);}
		}
		for(i=1;i<=n;i++){
			if(i>=sb2){
				res+=(ll)(sb)*a[i];
			}
			else{
				res+=(ll)(sb+1)*a[i];
			}
		}
		printf("%lld\n",res);
	}
}