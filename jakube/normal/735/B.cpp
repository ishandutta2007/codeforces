#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, n1, n2;
    cin >> n >> n1 >> n2;
    
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    sort(v.begin(), v.end(), greater<int>());
    if (n1 > n2) {
        swap(n1, n2);
    }

    long long a = 0, b = 0;
    for (int i = 0; i < n1; i++) {
        a += v[i];
    }
    for (int i = n1; i < n1+n2; i++) {
        b += v[i];
    }

    cout << a/(double)n1 + b/(double)n2 << endl;


    return 0;
}