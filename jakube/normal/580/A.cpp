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
    
    int m = 1;
    int c = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] >= v[i-1]) {
            c++;
            m = max(m, c);
        }
        else {
            c = 1;
        }
    }
    cout << m << endl;


    return 0;
}