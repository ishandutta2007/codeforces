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
    
    int a = max_element(v.begin(), v.end()) - v.begin();
    int b = min_element(v.rbegin(), v.rend()) - v.rbegin();

    int c = a + b;
    if (a >= N-1 - b) {
        c--;
    }

    cout << c << endl;
    return 0;
}