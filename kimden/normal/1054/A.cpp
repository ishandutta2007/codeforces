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
    ll x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    if((abs(z - x) + abs(x - y)) * t2 + 3 * t3 <= abs(x - y) * t1) {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }


}