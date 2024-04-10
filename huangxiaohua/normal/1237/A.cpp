#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[66666];

int main(){
	t=1;
	while(t--){
		sb=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]&1){sb++;}
		}
		sb/=2;
		for(i=1;i<=n;i++){
			if(a[i]&1){
				if(a[i]>0){a[i]/=2;}
				else{a[i]=a[i]/2-1;}
				
				
				if(sb){a[i]++;sb--;}
			}
			else{
				a[i]/=2;
			}
			printf("%d\n",a[i]);
		}
	}
}