#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        int mini = 1e9 + 1, maxi = 0;
        int a = -1, b = -1;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x < mini) {
                mini = x;
                a = i;
            }
            if(x > maxi) {
                maxi = x;
                b = i;
            }
        }
        cout << a+1 << ' ' << b+1 << '\n';
    }
}