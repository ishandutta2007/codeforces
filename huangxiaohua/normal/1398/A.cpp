#include<bits/stdc++.h>
using namespace std;

int n,i,t,a[66666],r1,r2,n1,n2;

int main(){
    scanf("%d",&t);
    while(t--){
    	r1=r2=0;
    	n1=n2=0;
    	scanf("%d",&n);
    	for(i=1;i<=n;i++){
    		scanf("%d",&a[i]);
		}
		r1=a[1];r2=a[2];
		for(i=3;i<=n;i++){
			if(a[i]>=r1+r2){
				printf("%d %d %d\n",1,2,i);goto aaa;
			}
		}
		puts("-1");
		aaa:continue;
	}
}