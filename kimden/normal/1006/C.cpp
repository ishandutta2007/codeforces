#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    int ptr1 = 0, ptr2 = n - 1;
    ll sum1 = 0, sum2 = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    while(ptr1 - ptr2 <= 1){
        if(sum1 == sum2){
            ans = max(ans, sum1);
            sum1 += a[ptr1++];
            sum2 += a[ptr2--];
        }else {
            if (sum1 < sum2) {
                sum1 += a[ptr1++];
            } else {
                sum2 += a[ptr2--];
            }
        }
    }

    cout << ans << endl;
    return 0;
}