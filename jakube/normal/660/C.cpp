#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] = 1 - v[i];
    }
    
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + v[i];
    }
    
    vector<int> longest_zero(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i-1] != 0) {
            longest_zero[i] = 0;
        } else {
            longest_zero[i] = longest_zero[i-1] + 1;
        } 
    }

    int best_result = 0;
    int position = 0;
    for (int i = 0; i < n; i++) {
        int pos;
        if (k > 0) {
           pos = lower_bound(prefix.begin(), prefix.end(), prefix[i+1] - k + 1) - prefix.begin();
            if (pos > 0)
                pos--;
        }
        else 
            pos = i;

        if (k != 0 || v[pos] == 0) {
            pos -= longest_zero[pos];

            int length = i + 1 - pos;
            if (length > best_result) {
                best_result = length;
                position = pos;
            }
        }
    }
    
    for (int i = position; i < n && k > 0; i++) {
        if (v[i] == 1) {
            k--;
            v[i] = 0;
        }
    }

    cout << best_result << endl;
    for (int i = 0; i < n; i++) {
        cout << 1 - v[i] << " ";
    }
    cout << endl;
}