#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,t,a[300500],res,mx;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res=-1;mx=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		a[0]=a[n+1]=1145141919;
		for(i=1;i<=n;i++){
			if(a[i]==mx&&((a[i]>a[i-1])||(a[i]>a[i+1]))){res=i;break;}
		}
		printf("%d\n",res);
	}
}