#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
ll a[100500],res=1e15;
ll get(int l,int r){
	ll res=0;
	while(l<=r){
		res+=a[r]-a[l];
		l++;r--;
	}return res;
}

int main() {
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&k);
		if(k){a[++n]=i;}
	}
	if(n==1){puts("-1");return 0;}
	m=n;
	for(i=2;i<=m;i++){
		if(!(m%i)){
			while(!(m%i)){m/=i;}
			ll tmp=0;
			for(j=1;j<=n;j+=i){
				tmp+=get(j,j+i-1);
			}
			res=min(res,tmp);
		}
	}
	printf("%lld",res);
}