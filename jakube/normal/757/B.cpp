#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<int> cnt(1e5, 0);
    for (int i : v) {
        if (i % 2 == 0) {
            cnt[2]++;
            while (i % 2 == 0)
                i /= 2;
        }

        for (int d = 3; d*d <= i; d+=2) {
            if (i % d == 0) {
                cnt[d]++;
                while (i % d == 0) 
                    i /= d;
            }
        }

        if (i > 1)
            cnt[i]++;
    }
    cnt[1] = 1;

    cout << *max_element(cnt.begin(), cnt.end()) << endl;


    return 0;
}