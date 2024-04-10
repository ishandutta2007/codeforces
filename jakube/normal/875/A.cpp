#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> res;
    for (int i = max(n - 100, 1); i <= n; i++) {
        int j = i;
        int sum = i;
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        if (sum == n) {
            res.push_back(i);
        }
    }

    cout << res.size() << endl;
    for (int r : res) {
        cout << r << '\n';
    }
}