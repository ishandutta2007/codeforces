#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[300500],b[300500],cur;
ll res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		res=0;cur=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);
		}
		sort(a+1,a+n+1);
		for(i=n;i>=1;i--){
			cur++;
			res+=b[min(cur,a[i])];
		}
		printf("%lld\n",res);
	}
}