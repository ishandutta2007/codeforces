#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll sb1,sb2,a[300500];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i&1){
			sb1+=(a[i]+1)/2;
			sb2+=a[i]/2;
		}
		else{
			sb2+=(a[i]+1)/2;
			sb1+=a[i]/2;
		}
	}
	printf("%lld",min(sb1,sb2));
}