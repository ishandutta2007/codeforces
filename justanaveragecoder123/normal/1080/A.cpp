#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int main() {
	int n,k;
	cin>>n>>k;
	cout<<((2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k)<<"\n";
	return 0;
}