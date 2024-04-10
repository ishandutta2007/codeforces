#include<bits/stdc++.h>
using namespace std;

int n,k,a[200500],b[200500],ab[200500],sum,t1,t2,t3,i,j,l;

int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(t2==1&&t3==0){
			a[0]++;a[a[0]]=t1;
		}
		if(t2==0&&t3==1){
			b[0]++;b[b[0]]=t1;
		}
		if(t2==1&&t3==1){
			ab[0]++;ab[ab[0]]=t1;
		}
	}
	if(a[0]+ab[0]<k||b[0]+ab[0]<k){puts("-1");return 0;}
	sort(a+1,a+a[0]+1);
	sort(b+1,b+b[0]+1);
	sort(ab+1,ab+ab[0]+1);
	for(i=1;i<=min(min(a[0],b[0]),k);i++){
		sum+=a[i];sum+=b[i];
	}
	if(min(a[0],b[0])<k){
		for(i=1;i<=k-min(a[0],b[0]);i++){
			sum+=ab[i];
		}
	}
	i=j=min(k,min(a[0],b[0]));
	l=max(1,k-min(a[0],b[0])+1);
	while(i>=1&&j>=1&&l<=ab[0]){
		if(a[i]+b[j]>=ab[l]){
			sum-=a[i];sum-=b[j];sum+=ab[l];
			i--;j--;l++;
		}else{break;
		}
	}
	printf("%d",sum);
}