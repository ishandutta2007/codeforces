#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;

bool check(int a, int b){
	return 2*a>=b && a <= b;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll v1, v2, v3, vm;
	cin >> v1 >> v2 >> v3 >> vm;
	for(int i = vm; i <= 300; i++)
		if(check(v1, i)&&!check(vm, i))
		for(int j = vm; j < i; j++)
			if(check(v2, j)&&!check(vm, j))
			for(int k = vm; k <= j; k++)
				if(check(v3, k)&&check(vm, k))
					return cout << i << "\n" << j << "\n" << k, 0;
	cout << -1;
}