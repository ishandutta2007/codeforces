#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bool> informed(n, false);
    informed[0] = true;
    int informed_cnt = 1;

    vector<pair<int,int>> output;

    while (informed_cnt < n) {
        // search for informed student with biggest
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (informed[i] && a[best] < a[i])
                best = i;
        }

        if (a[best] == 0) {
            cout << -1 << endl;
            return 0;
        }

        // find uninformed with max
        int best2 = 0;
        for (int i = 0; i < n; i++) {
            if (!informed[i] && (best2 == 0 || a[best2] < a[i]))
                best2 = i;
        }

        output.push_back({best+1, best2+1});
        a[best]--;
        informed[best2] = true;
        informed_cnt++;
    }

    cout << output.size() << endl;
    for (auto i : output)
        cout << i.first << ' ' << i.second << endl;
}