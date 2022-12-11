#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll inf = 2e9 + 1;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    int n, q, pos;
    cin >> n >> q >> pos;

    string s;
    cin >> s;

    vector<int> corr(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            int x = st.top();
            st.pop();
            corr[i] = x, corr[x] = i;
        }
    }

    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        l[i] = i - 1, r[i] = i + 1;
    }
    l[0] = r[n - 1] = -1;

    --pos;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'L') {
            pos = l[pos];
        } else if (c == 'R') {
            pos = r[pos];
        } else {
            int x, y;
            if (pos < corr[pos]) {
                x = l[pos], y = r[corr[pos]];
            } else {
                x = l[corr[pos]], y = r[pos];
            }
            if (x != -1) {
                r[x] = y;
            }
            if (y != -1) {
                l[y] = x;
            }
            if (y != -1) {
                pos = y;
            } else {
                pos = x;
            }
        }
    }

    while (l[pos] != -1) {
        pos = l[pos];
    }
    for (; pos != -1; pos = r[pos]) {
        cout << s[pos];
    }
    cout << "\n";

}