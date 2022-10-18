#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int N;
    cin >> N;
    vector<int> v(N);
    for (int idx = 0; idx < N;  idx++)
        cin >> v[idx];
    
    int mi = v[0];
    int ma = v[0];

    int c = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > ma)
        {
            c++;
            ma = v[i];
        }
        if (v[i] < mi) {
            c++;
            mi = v[i];
        }
    }

    cout << c << endl;

    return 0;
}