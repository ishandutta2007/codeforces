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
    
    int unique2 = 0;
    vector<int> cnt_right(1e5+1, 0);
    for (int x : v) {
        if (cnt_right[x] == 0)
            unique2++;
        cnt_right[x]++;
    }

    long long result = 0;
    vector<bool> left(1e5+1, false);
    for (int x : v) {
        cnt_right[x]--;
        if (cnt_right[x] == 0)
            unique2--;
        if (!left[x])
            result += unique2;
        left[x] = true;
    }
    cout << result << '\n';
}