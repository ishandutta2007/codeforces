#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++m[a[i]];
    }

    int cnt = 0;
    for (auto& it : m) {
        cnt = max(cnt, it.second);
    }

    m.clear();
    for (int i = 0; i < n; ++i) {
        ++m[a[i]];
        if (m[a[i]] == cnt) {
            cout << a[i] << "\n";
            return 0;
        }
    }

}