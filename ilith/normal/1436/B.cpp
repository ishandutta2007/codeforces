#include<bits/stdc++.h>
using namespace std;
long long t,n,m,u;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			if(i==1){
				printf("1 1 ");
				for(int j=3;j<=n;j++){
					printf("0 ");
				}
				puts("");
			}
			else if(i==n){
				printf("1 ");
				for(int j=3;j<=n;j++){
					printf("0 ");
				}
				printf("1 ");
				puts("");
			}
			else{
				for(int j=1;j<=n;j++){
					printf("%d ",(j==i||j==i+1));
				}
				puts("");
			}
		}
	}
	return 0;
}