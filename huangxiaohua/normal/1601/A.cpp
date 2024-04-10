#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[66],sb;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sb=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			sb|=k;
			for(j=1;j<=30;j++){
				if(k&b(j))a[j]++;
			}
		}
		if(!sb){
			for(i=1;i<=n;i++)printf("%d ",i);
			puts("");continue;
		}
		sb=0;
		for(i=1;i<=30;i++){
			sb=__gcd(sb,a[i]);
		}
		for(i=1;i<=sb;i++){
			if(!(sb%i))printf("%d ",i);
		}
		puts("");
	}
}