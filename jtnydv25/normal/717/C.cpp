#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n,i,ans=0;
	cin >> n;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	for(i=0;i<n;i++)
		a[i]%=10007;
	for(i=0;i<n;i++)		
		ans=(ans+a[i]*a[n-1-i])%10007;
	cout<<ans;
}