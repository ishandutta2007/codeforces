#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tmp;
int n,t,k,i,a[200500],b[200500],l,r;
int cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);tmp=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=k;i++){
			scanf("%d",&b[i]);
			if(b[i]==1){b[i]=999999;
			}
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+k,cmp);
		
		
		l=1;r=n;
		for(i=1;i<=k;i++){
			if(b[i]==999999){
				tmp+=2*a[r];r--;continue;
			}
			else{
				tmp+=a[r];tmp+=a[l];
			}
			r--;l+=(b[i]-1);
		}
		printf("%lld\n",tmp);
	}
}