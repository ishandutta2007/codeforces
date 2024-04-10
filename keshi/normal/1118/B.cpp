#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,a[200010],b[200010],s=0,c[200010],ans=0,d;
	cin >> n;
	for (ll i=0; i<n ;i++){
		cin >> a[i];
		if (i>0){
			b[i]=b[i-1];
			c[i]=c[i-1];
			if (i%2==0){
			    b[i]+=a[i];
			}
			else{
			    c[i]+=a[i];
			}
		}
		else{
		    b[i]=a[i];
		    c[i]=0;
		}
		s+=a[i];
	}
	for (ll i=0; i<n; i++){
		d=s-a[i];
		if (d%2==0){
			if (b[i-1]+c[n-1]-c[i]==d/2){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}