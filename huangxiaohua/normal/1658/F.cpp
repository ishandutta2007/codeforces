#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],p[200500],sb;
string s;

int main() {
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%1d",&a[i]);
			p[i]=p[i-1]+a[i];
		}
		sb=1ll*m*p[n]/n;
		if((1ll*sb*n)!=(1ll*m*p[n])){
			puts("-1");continue;
		}
		for(i=m;i<=n;i++){
			if(p[i]-p[i-m]==sb){
				printf("1\n%d %d\n",i-m+1,i);
				goto aaa;
			}
		}
		while(1){
			i=1;
			uniform_int_distribution<int>lim(1,m);
			j=lim(rng);
			for(k=i+j;k+(m-j-1)<=n;k++){
				if( (p[i+j-1]-p[i-1])+(p[k+m-j-1]-p[k-1])==sb ){
					printf("2\n%d %d %d %d\n",i,i+j-1,k,k+m-j-1);
					goto aaa;
				}
			}
		}
		aaa:;
	}
	
}