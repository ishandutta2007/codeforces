#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << (i << 7) << ' ';
    }
    cout << endl;
    int res1;
    cin >> res1;
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << i << ' ';
    }
    cout << endl;
    int res2;
    cin >> res2;
    int out = 0;
    for (int i = 0; i < 7; i++) {
        if (res1 & (1 << i)) out |= (1 << i);
    }
    for (int i = 7; i < 14; i++) {
        if (res2 & (1 << i)) out |= (1 << i);
    }
    cout << "! " << out << endl;
}