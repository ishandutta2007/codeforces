#include <bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define pb push_back

typedef long long ll;
typedef vector<int> vi;

const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i ^ n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k) {
        cout << "No" << endl;
        return 0;
    }
    int fuck = sum / k;
    vi out;
    for (int i = 0, cnt = 0, rem = 0; i ^ n; ++i) {
        rem += a[i];
        ++cnt;
        if (rem > fuck) {
            cout << "No" << endl;
            return 0;
        }
        if (rem == fuck) {
            out.pb(cnt);
            rem = cnt = 0;
        }
    }

    cout << "Yes" << endl << out.front();
    for (int i = 1; i ^ k; ++i) {
        cout << ' ' << out[i];
    }
    cout << endl;

    return 0;
}