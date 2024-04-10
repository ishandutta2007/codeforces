#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int d[MAXN];
int nxt[MAXN];

main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        arr.push_back({d[i], i});
    }
    sort(arr.begin(), arr.end());
    deque<int> st;
    for (int i = 1; i < n; ++i) {
        int x = arr[i - 1].second;
        int y = arr[i].second;
        cout << 2 * x + 1 << " " << 2 * y + 1 << endl;
        nxt[2 * y + 1] = 2 * x + 1;
    }
    st.push_back(2 * arr.back().second + 1);
    for (int i = 1; i < d[arr.back().second]; ++i) {
        st.push_back(nxt[st.back()]);
    }
    int x = st.back();
    bool f = true;
    for (int i = n - 1; i >= 0; --i) {
        while (st.size() > arr[i].first) {
            st.pop_back();
            if (st.back() % 2 == 1) {
                x = st.back();
            }
        }
        cout << st.back() << " " << arr[i].second * 2 + 2 << endl;
        st.push_back(arr[i].second * 2 + 2);
        if (arr[i].second == x / 2) {
            f = false;
        }
        if (f) {
            st.pop_front();
        } else if (i != 0) {
            st.push_front(arr[i - 1].second * 2 + 1);
        }
    }
    return 0;
}