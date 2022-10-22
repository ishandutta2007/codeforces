#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#define LL long long
#define N 100050
using namespace std;
int x,n,m,k;
int main(){
	int t;bool flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(!x){
			printf("1 1\n");continue;
		}
		flag=0;
		for(int i=1;i<sqrt(x);i++){
			if(x%i) continue;
			if((x/i+i)&1) continue;
			n=(x/i+i)/2;m=(x/i-i)/2;k=n/m;
			if(k&&n/k==m){
				flag=1;break;
			}
			else if((k-1)&&n/(k-1)==m){
				flag=1;k=k-1;break;
			}
			else if((k+1)&&n/(k+1)==m){
				flag=1;k=k+1;break;
			}
		}
		if(!flag){
			printf("-1\n");continue;
		}
		else{
			printf("%d %d\n",n,k);continue;
		}
	}
}