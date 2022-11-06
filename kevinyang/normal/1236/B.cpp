#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = (int)1e9+7;
int power(int a,int b){
	if(b==1)return a;
	if(b%2==0)return power((a*a)%mod,b/2);
	return (power(a,b-1)*a)%mod;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	cout << (power(power(2,m)-1,n))%mod<<"\n";
	return 0;
}