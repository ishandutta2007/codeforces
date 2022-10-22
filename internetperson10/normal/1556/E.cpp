#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll ma[100001][20], mi[100001][20];

ll maxi(int x, int y) {
    int g = 0;
    while(y - x + 1 >= (1 << g)) g++;
    g--;
    return max(ma[x][g], ma[y-(1<<g)+1][g]);
}
ll mini(int x, int y) {
    int g = 0;
    while(y - x + 1 >= (1 << g)) g++;
    g--;
    return min(mi[x][g], mi[y-(1<<g)+1][g]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n), pref(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[i] = x - nums[i]; 
        if(i == 0) pref[i] = nums[i];
        else pref[i] = pref[i-1] + nums[i];
    }
    for(int i = 0; i < n; i++) ma[i][0] = mi[i][0] = pref[i];
    for(int j = 1; j < 20; j++) {
        for(int i = 0; i < n; i++) {
            int g = (1 << (j-1)) + i;
            if(g > n) {
                ma[i][j] = ma[i][j-1];
                mi[i][j] = mi[i][j-1];
            }
            else {
                ma[i][j] = max(ma[i][j-1], ma[g][j-1]);
                mi[i][j] = min(mi[i][j-1], mi[g][j-1]);
            }
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        bool ok = true;
        ll g;
        if(x) g = pref[x-1];
        else g = 0;
        if(pref[y] - g) ok = false;
        if(mini(x, y) < g) ok = false;
        if(!ok) {
            cout << -1 << '\n';
        }
        else {
            cout << maxi(x, y) - g << '\n';
        }
    }
}