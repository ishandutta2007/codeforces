#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define b(x) (1<<((x)-1))

int i,j,k,n,t,m,a[200500],r[200500],num[200500],res,mx,sb;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>t;
	res=n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
		r[a[i]]=i;
	}
	for(i=1;i<=n;i=j+1){
		j=i;sb=r[a[i]];
		mx=0;
		while(1){
			sb=max(sb,r[a[j]]);
			mx=max(mx,num[a[j]]);
			if(j==sb)break;
			else j++;
		}
		//printf("NMSL%d %d %d\n",i,j,mx);
		res-=mx;
	}
	cout<<res;
}