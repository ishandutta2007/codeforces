#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n >= 1 && n <= 9){
        cout << n << endl;
        return 0;
    }
    ll x = 9;
    while(10 * x + 9 <= n){
        x *= 10;
        x += 9;
    }
    ll o = n - x;
    ll ans = 0;
    while(o){
        ans += o % 10;
        o /= 10;
    }
    while(x){
        ans += x % 10;
        x /= 10;
    }
    cout << ans << endl;


    return 0;
}