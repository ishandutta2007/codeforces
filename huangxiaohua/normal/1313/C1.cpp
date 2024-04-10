#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[500500],res,sb,tmp,id,b[500500];

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++){
		sb=a[i];tmp=a[i];
		for(j=i-1;j>=1;j--){
			sb=min(sb,a[j]);
			tmp+=sb;
		}
		sb=a[i];
		for(j=i+1;j<=n;j++){
			sb=min(sb,a[j]);
			tmp+=sb;
		}
		//printf("NMSL%d %d\n",i,tmp);
		if(tmp>res){
			res=tmp;id=i;
		}
	}
	for(i=id-1;i>=1;i--){
		a[i]=min(a[i],a[i+1]);
	}
	for(i=id+1;i<=n;i++){
		a[i]=min(a[i],a[i-1]);
	}
	for(i=1;i<=n;i++)cout<<a[i]<<' ';
}