#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	ll n,m,k,ans=0;
	string s;
	cin >> n >> m;
	if (n%2==0 || m%2==0){
		cout << m*n/2;
	}
	else if(m>n){
		cout << (m-1)/2*n+n/2;
	}
	else{
		cout << (n-1)/2*m+m/2;
	}
	
	return 0;
}