#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,ans=0;
	cin >> n >> m;
	m--;
	int a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=0;i<n;i++){
		if (a[i]>=a[m] && a[i]>0){
			ans++;
		}
	}
	cout << ans;
	return 0;
}