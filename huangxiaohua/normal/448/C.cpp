#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[5050];

int get(int l,int r,int h){
	if(l>=r){return (l==r);}
	int i,j=l,k,mn=1e9,tmp=0;
	for(i=l;i<=r;i++){
		mn=min(mn,a[i]);
	}
	for(i=l;i<=r;i++){
		if(a[i]==mn){
			tmp+=get(j,i-1,mn);j=i+1;
		}
	}
	tmp+=get(j,r,mn);
	return min(r-l+1,tmp+mn-h);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",get(1,n,0));
}