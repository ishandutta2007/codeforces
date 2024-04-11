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
    vector<int> st = {4, 8, 15, 16, 23, 42};
    int q[4];
    cout << "? 1 2" << endl;
    cin >> q[0];
    cout << "? 2 3" << endl;
    cin >> q[1];
    cout << "? 4 5" << endl;
    cin >> q[2];
    cout << "? 5 6" << endl;
    cin >> q[3];
    do {
        bool ok = true;
        if(st[0] * st[1] != q[0]) ok = false;
        if(st[1] * st[2] != q[1]) ok = false;
        if(st[3] * st[4] != q[2]) ok = false;
        if(st[4] * st[5] != q[3]) ok = false;
        if(ok) break;
    } while(next_permutation(st.begin(), st.end()));
    cout << "!";
    for(int i = 0; i < 6; i++) cout << " " << st[i];
    cout << endl;
    return 0;
}