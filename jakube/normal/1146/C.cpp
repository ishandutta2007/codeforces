#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n;
        cin >> n;
        int bit = 0;
        int maxx = 0;
        while (true) {
            vector<int> set1, set2;
            for (int i = 0; i < n; i++) {
                if (i & (1 << bit))
                    set1.push_back(i);
                else
                    set2.push_back(i);
            }

            if (set1.empty() || set2.empty())
                break;

            cout << set1.size() << " " << set2.size() << " ";
            for (int x : set1)
                cout << x + 1 << " ";
            for (int x : set2)
                cout << x + 1 << " ";
            cout << endl;
            int d;
            cin >> d;
            maxx = max(maxx, d);
            bit++;
        }
        cout << -1 << " " << maxx << endl;
    }
}