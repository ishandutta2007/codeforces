#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[100500],b[2];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]&1]++;
	}
	if(b[0]&&b[1]){sort(a+1,a+n+1);}
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
}