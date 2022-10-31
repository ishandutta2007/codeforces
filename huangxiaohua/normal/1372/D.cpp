#include <bits/stdc++.h>
using namespace std;
long long t,a[200500],i,c,d,m;
main(){
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&a[i]);
	}
	c=d=a[1];
	for(i=2;i<=t;i++){
		if(i%2==0){c+=a[i];}
		else{d+=a[i];}
	}
	m=max(c,d);
	for(i=3;i<=t;i+=2){
		c+=a[i]-a[i-1];
		d+=a[i-1]-a[i-2];
		m=max(max(c,d),m);
	}
	printf("%lld\n",m);
}