#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> result;
    int new_numbers = 0;
    for (int i = 0; i < n-1; i++) {
        result.push_back(v[i]);
        if (__gcd(v[i], v[i+1]) != 1) {
            int l = 2;
            while (__gcd(l, v[i]) != 1 || __gcd(l, v[i+1]) != 1)
                l++;
            result.push_back(l);
            new_numbers++;
        }
    }
    result.push_back(v.back());

    cout << new_numbers << endl;
    for (int i : result)
        cout << i << ' ';
    cout << endl;
}