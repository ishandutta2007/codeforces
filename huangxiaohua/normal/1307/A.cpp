#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];

double x=1,y;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=2;i<=n;i++){
			while(a[i]&&m>=i-1){
				m-=i-1;a[1]++;a[i]--;
			}
		}
		printf("%d\n",a[1]);
	}
}