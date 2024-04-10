#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int idx = 0; idx < N;  idx++)
        cin >> v[idx].first >> v[idx].second;
    
    int a = 0;
    int b = 0;

    for (auto p : v) {
        if (p.first == 1)
            a++;
        if (p.second == 1)
            b++;
    }

    cout << min(a, N-a) + min(b, N-b) << endl;



    return 0;
}