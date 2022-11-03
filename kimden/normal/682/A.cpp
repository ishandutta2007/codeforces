#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000007
typedef long long ll;

int main()
{
	int n,m;
	cin >> n >> m;
	int a = n%5,b = m%5;
	ll c[6],d[6];
	ll ans=0;
	for(int i=1;i<=5;i++){
		c[i] = n/5;
		d[i] = m/5;
		if(i<=a){
			c[i]++;
		}
		if(i<=b){
			d[i]++;
		}
	}
	ans += c[5]*d[5];
	for(int i=1;i<5;i++){
		ans += c[i]*d[5-i];
	}
	cout << ans;
}