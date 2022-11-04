#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi am(3);

void win(ll a, ll b, ll c) {
    ll d1 = b - a;
    ll d2 = c - b;
    cout << 2 * d2 + d1 << endl;
    int k;
    cin >> k;
    --k;
    if(k == -1) {
        return;
    }
    if(am[k] == 0) {
        cout << d2 << endl;
    } else {
        cout << d1 + d2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    vector<pair<ll, int>> mass(3);
    for(int i = 0; i < 3; i++) {
        cin >> mass[i].first;
        mass[i].second = i;
    }
    sort(mass.begin(), mass.end());
    for(int i = 0; i < 3; i++) {
        am[mass[i].second] = i;
    }
    ll a = mass[0].first;
    ll b = mass[1].first;
    ll c = mass[2].first;
    cout << "First" << endl;
    cout << 1 << endl;
    int k;
    cin >> k;
    --k;
    if(am[k] == 2) {
        ++c;
        win(a, b, c);
    } else if(am[k] == 1) {
        ++b;
        cout << b - a << endl;
        cin >> k;
        if(k == 0) {
            return 0;
        }
        win(a, b, c + b - a);
    } else {
        ++a;
        cout << c - b << endl;
        cin >> k;
        if(k == 0) {
            return 0;
        }
        win(a, b, c + c - b);
    }
}