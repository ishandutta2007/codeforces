#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[200500];

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(!a[i])continue;
		k++;
		for(j=i+1;j<=n;j++){
			if(!(a[j]%a[i]))a[j]=0;
		}
	}
	cout<<k;
}