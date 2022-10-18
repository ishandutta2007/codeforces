#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> v[i];
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = 2*i;
        int y = 2*i + 1;
        while (v[y] != v[x])
            y++;
        while (y > 2*i + 1) {
            res++;
            swap(v[y], v[y-1]);
            y--;
        }
    }
    cout << res << '\n';
    
}