#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        int n;
        cin >> n;
        vector<int> d(n-1);
        for (int i=0; i<n-1; i++)
                cin >> d[i];
        int a, b;
        cin >> a >> b;
        cout << accumulate(d.begin()+a-1, d.begin()+b-1, 0) << '\n';
}