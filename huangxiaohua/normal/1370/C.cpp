#include<bits/stdc++.h>
using namespace std;

int a,i,j,t,b,c;

int main(){
	scanf("%d",&t);
	while(t--){
		c=0;
		scanf("%d",&a);
		if(a==2){
			puts("Ashishgup");continue;
		}
		if(a==1){
			puts("FastestFinger");continue;
		}
		if(a%2==1){
			puts("Ashishgup");continue;
		}
		b=a;
		while(b%2==0){
			b/=2;
		}
		if(b!=1&&a%4==0){
			puts("Ashishgup");continue;
		}
		if(b==1&&a%2==0){
			puts("FastestFinger");continue;
		}
		b=a/2;
		for(i=3;i<=sqrt(b);i+=2){
			if(b%i==0){puts("Ashishgup");goto aaa;
			}
		}
		puts("FastestFinger");
		
		aaa:continue;
	}
}