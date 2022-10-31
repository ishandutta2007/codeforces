#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

int i,j,n,t,res;
char a[1005];

int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&n);
		gets(a+1);res=0;
		if(n==1){
			puts(((a[1]-'0')%2)?"1":"2");continue;
		}
		if(n%2==0){
			for(i=2;i<=n;i+=2){
				if((a[i]-'0'+1)%2){res=1;}
			}
			puts(res?"2":"1");
		}
		else{
			for(i=1;i<=n;i+=2){
				if((a[i]-'0')%2){res=1;}
			}
			puts(res?"1":"2");
		}
		
	}
}