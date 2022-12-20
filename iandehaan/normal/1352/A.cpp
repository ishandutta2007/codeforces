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
        int ten = 1;
        vector<int> out;
        for (int i = 0; i < 5; i++) {
            int blah = (n / ten)%(10);
            blah *= ten;
            if (blah != 0) out.pb(blah);
            ten *= 10;
        }
        cout << out.size() << endl;
        for (int thing : out) cout << thing << ' ';
        cout << endl;
    }
}