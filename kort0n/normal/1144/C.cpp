#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    set<int> st[2];
    int n;
    cin >> n;
    while(n--) {
        int in;
        cin >> in;
        if(st[0].find(in) == st[0].end()) st[0].insert(in);
        else if(st[1].find(in) == st[1].end()) st[1].insert(in);
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << st[0].size() << endl;
    for(auto itr = st[0].begin(); itr != st[0].end(); itr++) cout << *itr << " ";
    cout << endl;
    cout << st[1].size() << endl;
    auto itr = st[1].end();
    while(itr != st[1].begin()) {
        itr--;
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}