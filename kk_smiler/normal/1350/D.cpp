#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,q;
int a[100010],sum[100010];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		bool flag=false,can=false;
		if(n==1) can=true;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),flag|=(a[i]==k);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]>=k?1:-1);
		int mn=INT_MAX;
		for(int i=1;i<=n;i++){
			if(i>=2) mn=min(mn,sum[i-2]);
			if(sum[i]-mn>=1) can=true;
		}
		puts(flag&&can?"yes":"no");
	}
}