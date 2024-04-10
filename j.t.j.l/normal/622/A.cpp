#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MM = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int main(){
	ll n;
	cin>>n;
	ll x = sqrt(2 * n);
	while(x * (x + 1) / 2 >= n)
		x--;
	while((x + 2) * (x + 1) / 2 < n)
		x++;
	cout<<n - x* (x + 1) /2<<endl;
	return 0;
}