#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,ll> a;
int i,j,k,n,m,t;
ll res;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		a[k-i]+=k;
		res=max(res,a[k-i]);
	}
	printf("%lld",res);
}