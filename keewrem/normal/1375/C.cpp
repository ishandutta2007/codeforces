#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll N;

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        vi v(N);
        for (auto &x : v)
            cin >> x;
        if(v[0]>v[N-1])cout <<"NO\n";
        else cout << "YES\n";
    }
    return 0;
}