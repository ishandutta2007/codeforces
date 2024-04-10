#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,i,j,t,a[105][105];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j]=0;
			}
		}
		for(i=0;i<n;i++){
			a[i][i]=1;
			a[i][(i+1)%n]=1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d ",a[i][j]);
			}puts("");
		}
	}
}