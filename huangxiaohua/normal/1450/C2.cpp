#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,t,res,a[4];
char sb[305][305];
 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		a[1]=a[2]=a[3]=0;
		for(i=1;i<=n;i++){
			cin>>sb[i]+1;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if((i%3+j%3)%3==0){if(sb[i][j]=='X'){a[1]++;}}
				if((i%3+j%3)%3==1){if(sb[i][j]=='O'){a[1]++;}}
				
				if((i%3+j%3)%3==1){if(sb[i][j]=='X'){a[2]++;}}
				if((i%3+j%3)%3==2){if(sb[i][j]=='O'){a[2]++;}}
				
				if((i%3+j%3)%3==2){if(sb[i][j]=='X'){a[3]++;}}
				if((i%3+j%3)%3==0){if(sb[i][j]=='O'){a[3]++;}}
			}
		}
		//printf("%d %d %d\n",a[1],a[2],a[3]);
		
		if(a[1]<=a[2]&&a[1]<=a[3]){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if((i%3+j%3)%3==0){if(sb[i][j]=='X'){sb[i][j]='O';}}
					if((i%3+j%3)%3==1){if(sb[i][j]=='O'){sb[i][j]='X';}}
					printf("%c",sb[i][j]);
				}puts("");
			}puts("");goto aaa;
		}
		
		if(a[2]<=a[1]&&a[2]<=a[3]){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if((i%3+j%3)%3==1){if(sb[i][j]=='X'){sb[i][j]='O';}}
					if((i%3+j%3)%3==2){if(sb[i][j]=='O'){sb[i][j]='X';}}
					printf("%c",sb[i][j]);
				}puts("");
			}puts("");goto aaa;
		}
		
		if(a[3]<=a[2]&&a[3]<=a[1]){
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if((i%3+j%3)%3==2){if(sb[i][j]=='X'){sb[i][j]='O';}}
					if((i%3+j%3)%3==0){if(sb[i][j]=='O'){sb[i][j]='X';}}
					printf("%c",sb[i][j]);
				}puts("");
			}puts("");goto aaa;
		}
		aaa:;
	}
}