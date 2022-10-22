#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll BIG = 999999999999;
long long int sums[900001];

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long int n, sum = 100000, k, ans = 0;
        sums[100000]++;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            sum += (int)(s.at(i) - '1');
            ans += sums[sum];
            sums[sum]++;
        }
        sum = 100000;
        sums[sum]--;
        for(int i = 0; i < n; i++) {
            sum += (int)(s.at(i) - '1');
            sums[sum]--;
        }
        cout << ans << '\n';
    }
}