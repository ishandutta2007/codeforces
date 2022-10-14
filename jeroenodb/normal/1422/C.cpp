#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int mxN = 1e5+1, MOD = 1e9+7, HALVE = 5e8+4;
long long Mul(long long a, long long b) {
    return a*b%MOD;
}
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    long long power = 1, geosum=0;
    long long ans=0;
    for(int i=n-1;i>=0;--i) {
        long long subt = Mul(Mul(i,i+1),HALVE);
        subt = Mul(power,subt) + geosum % MOD;
        ans = (ans + Mul(subt,s[i]-'0')) % MOD;
        geosum = (geosum + power*(n-i)) % MOD;
        power = power*10 % MOD;
    }
    cout << ans << endl;


}
int main() {
    solve();
}