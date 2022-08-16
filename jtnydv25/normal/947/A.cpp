#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
vi primes;
const int N = 1e6;
int factor[N], mu[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) primes.pb(i), factor[i] = i;
}
vector<int> P;
int getMin(int l, int p){
	return p * ((l - 1) / p + 1);
}

int main(){
	pre();
	int x;
	cin >> x;
	for(int p : primes) if(x % p == 0) P.pb(p);
	int ans = 1e9;
	for(int p0 : primes){
		for(int p1 : P){
			int val = max(p1 + 1, getMin(x - p1 + 1, p0));
			if(val > x) continue;
			int f = max(p0 + 1, val - p0 + 1);
			if(f > val) continue;
			ans = min(ans, f);
		}
	}
	cout << ans;
}