#include<bits/stdc++.h>
#define right right1
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vi right(n);
    vi pos(n, -1);
    for(int i = n - 1; i >= 0; i--) {
        if(pos[a[i]] == -1) {
            pos[a[i]] = i;
        }
        right[a[i]] = pos[a[i]];
    }
    int ans = 0;
    int now = 0;
    int calc = -1;
    while(now < n) {
        ans += max(0, right[a[now]] - max(calc, now) - 1);
        int mxid = -1;
        int mxval = -1;
        for(int j = calc + 1; j <= right[a[now]]; j++) {
            if(mxval < right[a[j]]) {
                mxval = right[a[j]];
                mxid = j;
            }
        }
        //cout << now << ' ' << calc << ' ' << mxid << ' ' << mxval << endl;
        if(mxval > right[a[now]] + 1) {
            calc = right[a[now]];
            now = mxid;
        } else {
            now = right[a[now]] + 1;
            calc = now - 1;
        }
    }
    cout << ans;
}