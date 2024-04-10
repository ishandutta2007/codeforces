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
        map<int, int> ma;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ma[x]++;
        }
        int sum = 0;
        for(auto p : ma) sum += min(p.second, 2);
        cout << (sum+1)/2 << '\n';
    }
}