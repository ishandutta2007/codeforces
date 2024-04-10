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
    
    cout << accumulate(v.begin(), v.end(), 0LL) / (double)N << endl;

    return 0;
}