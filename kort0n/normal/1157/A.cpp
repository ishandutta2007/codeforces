#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
set<int> appeared;

int f(int in) {
    in++;
    while(in % 10 == 0) {
        in /= 10;
        if(in == 0) break;
    }
    return in;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 1;
    appeared.insert(n);
    while(true) {
        n = f(n);
        if(appeared.find(n) != appeared.end()) break;
        ans++;
        appeared.insert(n);
    }
    cout << ans << endl;
    return 0;
}