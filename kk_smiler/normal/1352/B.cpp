#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k,a;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&n);
		bool flag=false;
		if(a%2==0){
			if(n%2==0&&a>=n){
				flag=true;
				puts("YES");
				for(int i=1;i<n;i++) printf("1 ");
				printf("%d\n",a-n+1);
			}
			if(flag) continue;
			if(a>=2*n){
				flag=true;
				puts("YES");
				for(int i=1;i<n;i++) printf("2 ");
				printf("%d\n",a-2*n+2);
			} 
		}
		else{
			if(n%2==1&&a>=n){
				flag=true;
				puts("YES");
				for(int i=1;i<n;i++) printf("1 ");
				printf("%d\n",a-n+1);
			}
		}
		if(!flag) puts("NO");
	}
}