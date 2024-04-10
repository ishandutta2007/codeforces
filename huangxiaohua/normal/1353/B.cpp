#include<stdio.h>
#include<bits\stdc++.h>
using namespace std;
#define LL long long int
LL t,i,j,n,k,a[50],b[50],c,d,res,aa,bb;
int main(){
	scanf("%lld",&t);
	for(i=1;i<=t;i++){
		res=0;
		scanf("%lld%lld",&c,&d);
		for(j=1;j<=c;j++){
			scanf("%lld",&a[j]);
		}	
		for(j=1;j<=c;j++){
			scanf("%lld",&b[j]);
		}
		sort(a+1,a+c+1);
		sort(b+1,b+c+1);
		aa=bb=0;
		while(aa+bb<=c-1){
			if(b[c-bb]>a[c-aa]&&bb<=d-1){
				res+=b[c-bb];bb++;
			}
			else{
				res+=a[c-aa];aa++;
			}
		}
		printf("%lld\n",res);
	}

}