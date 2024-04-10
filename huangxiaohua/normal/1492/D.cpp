#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,a,b,r1[400500],r2[400500];

int main(){
	scanf("%d%d%d",&a,&b,&k);
	n=a+b;
	if(b==1){
		if(k){puts("No");return 0;}
		puts("Yes");
		printf("1");for(i=1;i<=a;i++){printf("0");}puts("");
		printf("1");for(i=1;i<=a;i++){printf("0");}puts("");
	}
	else{
		for(i=1;i<b;i++){
			r2[i]=r1[i]=1;
		}
		r2[n]=r1[n]=1;
		if(k<b-1){for(i=b-1;i>=b-1-k+1;i--){r1[i]++;}}
		else{for(i=1;i<=k;i++){r1[i]++;}}
		for(i=1;i<=n;i++){
			if(r1[i]>1){
				if(i==n){puts("No");return 0;}
				r1[i]-=2;r1[i+1]++;
			}
		}
		puts("Yes");
		for(i=n;i>=1;i--){printf("%d",r1[i]);}puts("");
		for(i=n;i>=1;i--){printf("%d",r2[i]);}puts("");
	}
}