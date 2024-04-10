#include <bits/stdc++.h>

using namespace std;

long long int MOD = 1000000007;
vector<bool> squares;
long long int arr[778][10];
long long int fact[1000001];

long long int inv(long long int n) {
	long long int ans=n;
	for(int a=squares.size()-2; a>=0; a--) {
		ans=ans*ans;
		ans%=MOD;
		if(squares[a]) {
			ans*=n;
			ans%=MOD;
		}
	}
	return ans;
}

bool isGood(int n, int a, int b) {
	while(n) {
		if((n%10)!=a && (n%10)!=b) return false;
		n/=10;
	}
	return true;
}

long long int numGood(int num, int n, int k, int a, int b) {
	if(!isGood(num, a, b)) return 0;
	//cout << num << ' ' << n << ' ' << k << ' ' << a << ' ' << b << '\n';
	return ((((inv(fact[n-k])*inv(fact[k]))%MOD)*fact[n])%MOD);
}

int main() {
	long long int z=MOD-2;
	while(z) {
		if(z%2) squares.emplace_back(true);
		else squares.emplace_back(false);
		//cout << z%2;
		z/=2;
	}
	//cout << '\n';
	fact[0]=1;
	for(int a=1; a<1000001; a++) fact[a]=((fact[a-1]*a)%MOD);
	long long int a, b, n, ans=0;
	cin >> a >> b >> n;
	int num = a*n;
	for(int x=0; x<=n; x++) {
		ans+=numGood(num, n, x, a, b);
		num+=b;
		num-=a;
		ans%=MOD;
	}
	cout << ans << '\n';
	//cout << fact[5] << ' ' << fact[8] << ' ' << ((fact[6]*inv(fact[3])%MOD)*inv(fact[3]))%MOD << '\n';
}