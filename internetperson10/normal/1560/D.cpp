#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> v1, v2;

ll moves() {
    int j = 0;
    int x = v2.size();
    v2.push_back(11);
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] == v2[j]) {
            j++;
            x--;
        }
        else {
            x += 1;
        }
    }
    //cout << x << '\n';
    return x;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll i = 1, ans = 999;
        while(n) {
            v1.push_back(n%10);
            n /= 10;
        }
        reverse(v1.begin(), v1.end());
        while(i <= (1LL << 61)) {
            //cout << i << '\n';
            ll j = i;
            while(j) {
                v2.push_back(j%10);
                j /= 10;
            }
            reverse(v2.begin(), v2.end());
            ans = min(ans, moves());
            vector<int>().swap(v2);
            i *= 2;
        }
        cout << ans << '\n';
        vector<int>().swap(v1);
    }

}