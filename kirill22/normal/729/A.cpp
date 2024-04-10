#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int tmp = 0;
    for (auto c : s) {
        if (c == 'o') {
            if (tmp % 2 == 0) tmp++;
            else {
                if (tmp >= 3 && tmp % 2 == 1) cout << "***";
                else if (tmp >= 3) cout << "***g";
                else if (tmp == 2) cout << "og";
                else if (tmp == 1) cout << "o";
                tmp = 1;
            }
        }
        else if (c == 'g') {
            if (tmp % 2 == 1) tmp++;
            else {
                if (tmp >= 3 && tmp % 2 == 1) cout << "***";
                else if (tmp >= 3) cout << "***g";
                else if (tmp == 2) cout << "og";
                else if (tmp == 1) cout << "o";
                tmp = 0;
                cout << "g";
            }
        }
        else {
            if (tmp >= 3 && tmp % 2 == 1) cout << "***";
            else if (tmp >= 3) cout << "***g";
            else if (tmp == 2) cout << "og";
            else if (tmp == 1) cout << "o";
            cout << c;
            tmp = 0;
        }
    }
    if (tmp >= 3 && tmp % 2 == 1) cout << "***";
    else if (tmp >= 3) cout << "***g";
    else if (tmp == 2) cout << "og";
    else if (tmp == 1) cout << "o";
}