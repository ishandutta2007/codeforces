#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,n,m,t,k,a[200050],b[200050],c[200050],d[200050];
ll res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(c,0,n*4+10);res=1;
		c[0]=1;a[0]=a[n+1]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			d[a[i]]=i;
		}
		for(i=1;i<=m;i++){
			scanf("%d",&b[i]);c[b[i]]=1;
		}
		for(i=1;i<=m;i++){
			k=2;
			if(c[a[d[b[i]]-1]]){k--;}if(c[a[d[b[i]]+1]]){k--;}
			res=res*k%M;if(!res){break;}c[b[i]]=0;
		}
		printf("%lld\n",res);
	}
}