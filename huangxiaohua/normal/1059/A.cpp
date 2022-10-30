#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int i,j,k,n,m,t,res,l[100500],r[100500];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	l[n+1]=m;
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	res+=l[1]/k;
	for(i=1;i<=n;i++){
		res+=(l[i+1]-r[i]-l[i])/k;
	}
	printf("%d",res);
}