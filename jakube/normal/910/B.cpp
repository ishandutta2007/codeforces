#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    
    vector<int> perm = {a, a, a, a, b, b};
    sort(perm.begin(), perm.end());
    
    int m = 6;
    do {
        int cur = n;
        int cnt = 0;
        for (int i = 0; i < 6; i++) {
            if (cur + perm[i] > n) {
                cur = 0;
                cnt++;
            }
            cur += perm[i];
        }
        m = min(m, cnt);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << m << '\n';
    
}