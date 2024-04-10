#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,l[200500],r[200500],a[200500],k1,k2,t;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		memset(r,-1,n*4+50);
		r[n]=0;
		k=a[n];
		for(i=n-1;i>=1;i--){
			r[i]=k;
			if(a[i]<k){break;}
			k=a[i]-k;
		}
		k=0;
		/*for(i=1;i<=n;i++){
			printf("%d ",r[i]);
		}puts("");*/
		
		for(i=1;i<=n;i++){
			if(i<n){
				k1=a[i+1]-k;
				k2=a[i]-k1;
				if(k1>=0&&k2>=0&&k2==r[i+1]){puts("YES");goto aaa;}
			}
			if(a[i]<k){break;}
			k=a[i]-k;
			if(k==r[i]){puts("YES");goto aaa;}
		}
		puts("NO");
		aaa:;
	}
}