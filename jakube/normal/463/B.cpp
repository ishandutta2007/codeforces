#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    cout << *max_element(v.begin(), v.end()) << endl;

    return 0;
}