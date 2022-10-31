#include<stdio.h>
#include<math.h>
#include <bits/stdc++.h>
#define LL long long int
 
using namespace std;
LL i,j,room[200005],m,n,tmp,no;
int main(){
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&m);
		for(j=1;j<=m;j++){
			room[j]=j;
		}
		for(j=1;j<=m;j++){
			scanf("%lld",&tmp);
			if(tmp<0){room[j]+=(m-abs(tmp)%m);room[j]%=m;room[j]++;}
			else{room[j]+=tmp%m;room[j]%=m;room[j]++;}
		}
		sort(room,room+m+1);
		for(j=1;j<=m;j++){
			if(room[j]!=j){
				printf("NO\n");no=1;break;
			}
		}
		if(no==1){no=0;continue;
		}
		printf("YES\n");
	}
}