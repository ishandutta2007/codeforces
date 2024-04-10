#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
ll n;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ll k=1;
	ll ans=0;
	while(n>1){
		ans+=k*(n/2);
		n-=n/2;
		k*=2;
	}
	cout << ans << endl;
}