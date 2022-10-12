/*input
5
2 1 2 2 3

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll n;
	cin>>n;
	ll ar[n];
	ll maxim = 0;
	for(ll i=0;i<n;i++) {
		cin>>ar[i];
		cout<<ar[i]+maxim<<" ";
		maxim = max(ar[i]+maxim, maxim);
	}
}