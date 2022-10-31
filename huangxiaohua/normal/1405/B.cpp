#include<bits/stdc++.h>
using namespace std;

int i,j,n,t;
long long a[100500],res,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		res=0;tmp=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]>=0){
				tmp+=a[i];
			}
			else{
				if(tmp+a[i]>=0){
					tmp+=a[i];
				}
				else{
					a[i]+=tmp;tmp=0;res-=a[i];
				}
			}
		}
		printf("%lld\n",res);
	}
}