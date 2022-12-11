#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    string s;
    getline(cin, s);

    int n = 0;
    vector<int> signs;
    signs.pb(1);

    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '-') {
            signs.pb(-1);
        } else if (s[i] == '+') {
            signs.pb(1);
        } else if (s[i] >= '0' && s[i] <= '9') {
            n *= 10;
            n += (s[i] - '0');
        }
    }

    int minn = 0, maxx = 0;
    int k = sz(signs);
    for (int i = 0; i < k; ++i) {
        if (signs[i] == 1) {
            maxx += n;
            minn += 1;
        } else {
            maxx -= 1;
            minn -= n;
        }
    }

    if (!(n >= minn && n <= maxx)) {
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";

    vector<int> ans(k, 1);
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += ans[i] * signs[i];
    }

    for (int i = 0; i < k; ++i) {
        while (true) {
            if (ans[i] < n && signs[i] == 1 && sum < n) {
                ++ans[i];
                ++sum;
            } else if (ans[i] < n && signs[i] == -1 && sum > n) {
                ++ans[i];
                --sum;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
        if (i != k - 1) {
            if (signs[i + 1] == 1) {
                cout << "+";
            } else {
                cout << "-";
            }
            cout << " ";
        }
    }
    cout << "= " << n << "\n";

}