#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,b[1000500],a[1000500],res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%1d",&b[i]);
	}
	for(i=1;i<=n;i++){
		if(a[i]!=b[i]&&a[i+1]!=b[i+1]){
			if(a[i]==b[i+1]&&a[i+1]==b[i]){
				res++;
				swap(a[i],a[i+1]);
			}
		}
	}
	for(i=1;i<=n;i++){
		res+=(a[i]!=b[i]);
	}
	printf("%d",res);
}