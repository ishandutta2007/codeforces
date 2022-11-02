#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int arr[MAXN], a[6];
vector<int> var[MAXN];
int ptr[MAXN];

int n;

bool check() {
    set<array<int, 2>> st;
    for (int i = 0; i < n; ++i) {
        st.insert({var[i][0], i});
        ptr[i] = 0;
    }
    int k = 2e9;
    while (true) {
        auto el = *st.begin();
        auto it = st.end();
        it--;
        int mx = (*it)[0];
        if (mx - el[0] < k) {
            k = mx - el[0];
        }
        st.erase(el);
        ptr[el[1]]++;
        if (ptr[el[1]] >= 6) {
            break;
        }
        st.insert({var[el[1]][ptr[el[1]]], el[1]});
    }
    cout << k << endl;
    return true;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 6; ++i) {
        cin >> a[i];
    }
    sort(a, a + 6);
    reverse(a, a + 6);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        for (int j = 0; j < 6; ++j) {
            var[i].push_back(arr[i] - a[j]);
        }
    }
    check();
    return 0;
}