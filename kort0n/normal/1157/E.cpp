#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int a[200050];
multiset<int> b;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        b.insert(in);
    }
    for(int i = 1; i <= n; i++) {
        auto itr = b.lower_bound(n-a[i]);
        if(itr != b.end()) {
            cout << (a[i] + *itr) % n << " ";
            b.erase(itr);
            continue;
        }
        itr = b.begin();
        cout << (a[i] + *itr) % n << " ";
        b.erase(itr);
    }
    cout << endl;
    return 0;
}