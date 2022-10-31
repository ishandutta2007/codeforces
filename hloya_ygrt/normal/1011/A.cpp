#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    int last = -1, cnt = 0, sum = 0;
    
    for (int i = 0; i < n && cnt < k; i++) {
        int cur = s[i] - 'a' + 1;
        if (cur > last + 1) {
            cnt += 1;
            last = cur;
            sum += cur;
        }
    }
    if (cnt < k)
        cout << -1;
    else
        cout << sum;
    return 0;
}