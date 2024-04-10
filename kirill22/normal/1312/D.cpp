#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const long long MOD = 998244353;
 
long long pw(long long a, int n){
if (n == 0)
return 1;
if (n % 2 == 1)
return a * pw(a, n - 1) % MOD;
auto tmp = pw(a, n / 2);
return tmp * tmp % MOD;
}
 
int main(){
#ifdef DEBUG
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#else
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
#endif
 
int n, m;
cin>> n>> m;
if (n == 2){
cout<< 0<< '\n';
return 0;
}
long long ans = 0;
long long C = 1;
long long kek = 1;
for (int i = 0; i < (n - 3); ++i)
kek = (kek * 2) % MOD;
for (int t = n - 1; t <= m; ++t){
ans += (n - 2) * C % MOD * kek % MOD;
C = C * t % MOD * pw(t + 2 - n, MOD - 2) % MOD;
}
cout<< ans % MOD<< '\n';
return 0;
}