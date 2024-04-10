#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050];
int min(int a,int b){return a<b?a:b;}

int main(){
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
		}
		a[n+1]=0;
		for(i=1;i<=min(1005,m);i++){
			for(j=1;j<=n;j++){
				k=(a[j-1]&&a[j-1]<=i)+(a[j+1]&&a[j+1]<=i);
				if(k==1){a[j]=i+1;}
			}
		}
		for(i=1;i<=n;i++){
			printf("%d",a[i]>0);
		}
		puts("");
	}
}