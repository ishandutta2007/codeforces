#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll back = 1;
    ll front = 1;
    while(s[front] == s[front - 1]) front++;
    while(s[n - back - 1] == s[n - back]) back++;
    front++;
    back++;
    ll ans = front + back - 1;
    if(s.back() == s[0]){
        cout << front * back % mod << endl;
        return 0;
    }
    cout << ans % mod << endl;
    return 0;
}