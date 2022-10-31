#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll n,i,j,k,tmp[666],mx;
 
int cmp(ll a,ll b){
	return a>b;
}
 
int main(){
	scanf("%d\n",&n);
	for(i=1;i<=n;i++){
		scanf("%llu",&tmp[i]);
	}
	sort(tmp+1,tmp+1+n,cmp);
	for(i=1;i<=n;i++){
		if(tmp[i]<tmp[1]/2){break;}
		for(j=i;j<=n;j++){
			for(k=j;k<=n;k++){
				mx=max(mx,tmp[i]|tmp[j]|tmp[k]);
			}
		}
	}
	printf("%llu",mx);
}