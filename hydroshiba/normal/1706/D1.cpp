#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

int inequality1(int a, int b){
    int ans = (1 << 12) - 1;

    for(int i = 11; i > -1; --i){
        if(ans == 1) break;
        if(b / (ans - (1 << i)) <= a) ans -= (1 << i);
    }

    return ans;
}

int inequality2(int a, int b){
    int ans = 0;

    for(int i = 11; i > -1; --i){
        if(ans == 1) break;
        if(b / (ans + (1 << i)) >= a) ans += (1 << i);
    }

    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = INT_MAX;
    int maxi = *a.rbegin() / k;

    for(int upper = 0; upper <= 800; ++upper){
        int res = (1 << 13) - 1;
        int upp = maxi + upper;

        for(int i = 12; i > -1; --i){
            int cur = res - (1 << i);
            if(cur >= upp){
                res = cur;
                continue;
            }

            int target = upp - cur;
            bool flag = false;

            for(int j = 0; j < n; ++j){
                int l = inequality1(upp, a[j]);
                int r = inequality2(target, a[j]);

                if(l > r){
                    flag = true;
                    break;
                }
            }

            if(!flag) res = cur;
        }

        ans = min(ans, res);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}