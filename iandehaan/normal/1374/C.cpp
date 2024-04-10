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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num = 0;
        string inp;
        cin >> inp;
        int out = 0;
        for (char c : inp) {
            if (c == '(') num--;
            else num++;
            if (num > 0) {
                num--;
                out++;
            }
        }
        cout << out << endl;
    }
}