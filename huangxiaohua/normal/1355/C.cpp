#include<stdio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<math.h>
#define LL long long int
using namespace std;
LL shit[5000055],a,b,c,d,i,j,sum,tmp;

int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(i=a+b;i<=b+c;i++){
		tmp=min(i-a-b+1,b+c-i+1);
		tmp=min(tmp,c-b+1);
		tmp=min(tmp,b-a+1);
		shit[i]=tmp;
	}
	for(i=c+b;i>=a;i--){
		shit[i]+=shit[i+1];
	}
	
	for(i=c;i<=d;i++){
		
		sum+=shit[i+1];
		if(shit[i+1]==0){break;
		}
	}
	printf("%lld",sum);
	return 0;
}