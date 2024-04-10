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
    int sum = accumulate(v.begin(), v.end(), 0);
    int mean = sum / N;

    if (mean * N != sum) cout << N - 1 << endl;
    else cout << N << endl;


    return 0;
}