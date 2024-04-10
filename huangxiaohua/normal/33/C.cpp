#include<bits/stdc++.h>
using namespace std;

int i,n,a[100500],sb[100500],tmp,res,t2,r2;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tmp+=a[i];res+=a[i];
		t2=min(t2,tmp);
		sb[i]=t2;
	}
	tmp=t2=0;
	for(i=n;i>=1;i--){
		tmp+=a[i];
		t2=min(t2,tmp);
		r2=max(r2,-(sb[i-1]+t2));
	}
	printf("%d",res+2*r2);
}