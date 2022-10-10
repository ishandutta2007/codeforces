#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int qq;
	cin >> qq;
	while(qq --){
		ll a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << "\n";
	}
	return 0;
}