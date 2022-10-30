#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a,b,x,y,l,r;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i*a<=n;i++){
		if(!((n-i*a)%b)){
			x=i;y=(n-i*a)/b;
			while(x||y){
				if(x){
					l=r+1;r=l+a-1;x--;
				}
				else{
					l=r+1;r=l+b-1;y--;
				}
				for(j=l+1;j<=r;j++){
					printf("%d ",j);
				}
				printf("%d ",l);
			}
			return 0;
		}
	}
	puts("-1");
}