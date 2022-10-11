#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a[150010],b,ans;
	cin >> n >> k;
	a[0]=0;
	for (int i=1; i<n+1; i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	b=a[k]-a[0];
	ans=1;
	for (int i=k+1; i<n+1; i++){
		if (b>a[i]-a[i-k]){
			b=a[i]-a[i-k];
			ans=i-k+1;
		}
	}
	cout << ans;
	return 0;
}