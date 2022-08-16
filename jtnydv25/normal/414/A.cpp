#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
const int N = 5000005;
int pr[5000005];
int primes[5000005];

int main(){

	for(int i = 2; i * i < N; i++)
		if(!pr[i])
			for(int j = i * i; j < N; j += i)
				pr[j] = 1;
	int cnt = 0;
	for(int i = 2; i < N; i++)
		if(!pr[i])
			primes[++cnt] = i;
	int n, k;
	cin >> n >> k;
	if(k < (n / 2)){
		cout << -1;
		return 0;
	}
	if(n == 1){
		if(k == 0){
			cout << 1;
			return 0;
		}
		cout << -1;
		return 0;
	}
	int x = k - n/2 + 1, y = 2 * x;
	cout << 2 * (k - n/2 + 1) << " " << k - n/2 + 1 << " ";
	cnt = 2;
	for(int i = 3; i <= n; i++){
		while(primes[cnt] == x || primes[cnt] == y)
			cnt++;
		cout << primes[cnt] << " ";
		cnt++;
	}
}