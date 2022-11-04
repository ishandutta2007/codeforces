#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi a;
int x;

bool check(int i, int prev) {
    ll sum = a[i];
    for(int j = 2; j <= 3; j++) {
        if(i - j + 1 < prev) {
            continue;
        }
        sum += a[i - j + 1];
        if((ll)j * x > sum) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        a.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> x;
        int ans = 0;
        int now = 0;
        ll sum = 0;
        int prev = -1;
        while(now < n) {
            if(prev == -1) {
                prev = now;
                sum = a[now];
                ++ans;
                ++now;
                continue;
            }
            ll sumnew = sum + a[now];
            if((ll)(now - prev + 1) * x <= sumnew && check(now, prev)) {
                sum = sumnew;
                ++ans;
                ++now;
                continue;
            }
            //cout << prev << ' ' << now << ' ' << sumnew << endl;
            prev = -1;
            ++now;
        }
        cout << ans << '\n';
    }
}