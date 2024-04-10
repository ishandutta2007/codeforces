#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,a[50500],b[50500],res,it,dis;

int main() {
	memset(a,1,sizeof(a));
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>k;
		b[j]++;
		if(k>j){
			a[j]=min(a[j],k-j);
		}
		else{
			a[j]=min(a[j],k-j+n);
		}
	}
	for(i=1;i<=n;i++){
		res=0;it=i;dis=-1;
		for(j=1;j<=n;j++){
			dis++;
			if(b[it]){
				res=max(res,(b[it]-1)*n+dis+a[it]);
			}
			it++;
			if(it>n)it=1;
		}
		cout<<res<<' ';
	}
}