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
    mu[1] = 1;
    for(int i = 2;i < N; i++){
        int p = factor[i], x = i/p;
        mu[i] = (x % p == 0) ? 0 : -mu[x];
    }   
}
vi sqf[2];

bool isp(int n){
    for(int k = 2; k * k <= n; k++) if(n % k == 0) return 0;
    return 1;
}
void go(int p, int ind, int x, int k, int n){
    if(primes[ind] >= p){
        sqf[k].pb(x);
        return ;
    }
    go(p, ind + 1, x, k, n);
    if(x * 1ll * primes[ind] <= n)
    go(p, ind + 1, x * primes[ind], k ^ 1, n);
}
void go(int p, int n){
    sqf[0].clear(); sqf[1].clear();
    if(n) go(p, 0, 1, 0, n);
}
int ans(int n, int p){
    if(!isp(p)) return 0;
    if(p * 1ll * p > n) return (p <= n);
    long long ans = 0;
    for(int x : sqf[0]){
        ans += (n / (p * x));
    }
    for(int x : sqf[1]){
        ans -= (n / (p * x));
    }
    return ans;
}
int main(){
    pre();
    int a, b, k;
    cin >> a >> b >> k;
    if(isp(k) && (k * 1ll * k <= b)) go(k, b / k);
    cout << ans(b, k) - ans(a - 1 , k) << endl;
}