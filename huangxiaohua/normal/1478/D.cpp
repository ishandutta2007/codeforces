#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){if(!b){return a;}return gcd(b,a%b);}

int i,j,n,t;
ll a[200500],tmp,k;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&k);
		tmp=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		for(i=1;i<n;i++){
			tmp=gcd(tmp,a[i+1]-a[i]);
		}
		a[1]=(a[1]%tmp+tmp)%tmp;
		k=(k%tmp+tmp)%tmp;
		if(k==a[1]){puts("YES");}
		else{puts("NO");}
	}
}