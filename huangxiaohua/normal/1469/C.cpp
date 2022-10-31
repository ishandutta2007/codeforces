#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,l,r,a[200500],no;

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		no=0;
		scanf("%d%d",&n,&k);
		scanf("%d",&a[1]);
		l=a[1]-(k-1),r=a[1]+k-1;
		for(i=2;i<=n-1;i++){
			scanf("%d",&a[i]);
			l=max(a[i],l);
			r=min(a[i]+k-1,r);
			//printf("%d l%d r%d\n",i,l,r);
			if(r<l){no=1;}
			l-=(k-1);
			r+=(k-1);
			//printf("%d l%d r%d\n",i,l,r);
		}
		scanf("%d",&a[n]);
		if(no){puts("NO");continue;}
		if(a[n]>=l&&a[n]<=r){puts("YES");}
		else{puts("NO");}
	}
}