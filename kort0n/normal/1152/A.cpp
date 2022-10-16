#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int key[2];
int box[2];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        key[in%2]++;
    }
    for(int i = 1; i <= m; i++) {
        int in;
        cin >> in;
        box[in%2]++;
    }
    cout << min(box[1], key[0]) + min(key[1], box[0]) << endl;
    return 0;
}