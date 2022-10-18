#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> v(4);
    for (int idx = 0; idx < 4;  idx++)
        cin >> v[idx];
    
    int N;
    cin >> N;
    
    int c = 0;
    for (int i = 1; i <= N; i++) {
        if (any_of(v.begin(), v.end(), [i](int a){return i%a==0;}))
            c++;
    }

    cout << c << endl;

    return 0;
}