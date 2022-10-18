#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (j < n) {
        if (v[j] > v[i]) {
            cnt++;
            i++;
        }
        j++;
    }
    cout << cnt << '\n';
}