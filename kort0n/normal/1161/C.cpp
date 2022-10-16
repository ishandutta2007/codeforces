#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int a[55];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int val = 1; val <= 50; val++) {
        int num = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == val) num++;
        }
        if(num == 0) continue;
        if(num >= n / 2 + 1) cout << "Bob" << endl;
        else cout << "Alice" << endl;
        return 0;
    }
    return 0;
}