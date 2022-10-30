#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[500500],res[500600],lst;

int main(){
	scanf("%d",&n);
	k=n;lst=n;
	for(i=n;i>=1;i--){
		for(j=i+i;j<=n;j+=i){
			if(!a[j]){k--;a[j]=1;}
		}
		for(j=k+1;j<=lst;j++){
			res[j]=i;
		}
		lst=k;
	}
	for(i=2;i<=n;i++){
		printf("%d ",res[i]);
	}
}