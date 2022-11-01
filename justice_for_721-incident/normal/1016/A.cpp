#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	int n;
	ll m;
	cin >> n >> m;
	ll cur=0;
	for(int i=1; i<=n ;i++){
		ll a;
		cin >> a;
		cout << (cur+a)/m << ' ';
		cur=(cur+a)%m;
	}
}