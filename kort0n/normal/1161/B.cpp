#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, m;
set<int> connected[200050];
int a[200050];
int b[200050];

bool can(int rot) {
    for(int i = 1; i <= m; i++) {
        int from = (a[i] + rot + n - 1) % n + 1; 
        int to = (b[i] + rot + n - 1) % n + 1;
        if(connected[from].find(to) == connected[from].end()) return false;
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        connected[a[i]].insert(b[i]);
        connected[b[i]].insert(a[i]);
    }
    vector<int> div;
    div.push_back(1);
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    for(int i = 0; i < div.size(); i++) {
        if(can(div[i])) {
            cerr << div[i] << endl;
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}