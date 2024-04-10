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

    int n;
    cin >> n;
    string inp;
    cin >> inp;
    int mx = 1;
    char lst = inp[0];
    for (int i = 1; i < n; i++) {
        if (inp[i] != lst) {
            mx++;
            lst = inp[i];
        }
    }
    cout << min(n, mx+2) << endl;
}