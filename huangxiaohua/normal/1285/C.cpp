#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin>>n;res=n;
	for(i=1;i*i<=n;i++){
		if(!(n%i)&&__gcd(i,n/i)==1)res=n/i;
	}
	cout<<n/res<<' '<<res;
}