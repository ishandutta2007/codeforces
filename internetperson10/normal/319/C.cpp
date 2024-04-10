#include <bits/stdc++.h>
typedef long long ll;
#define point complex<ll>

using namespace std;

// O(n^2) dp:
// dp[n] = min(dp[i] + a[n] * b[i])
//
// NO Li Chao tree in this house. I don't want to care about floats atm

struct line {
    ll x, y;
    line(ll x, ll y) : x(x), y(y) {}
    ll eval(ll k) {
        return x * k + y;
    }
    double intersect(line *l2) {
        return (double)(this->y - l2->y) / (this->x - l2->x);
    }
};

ll a[100001], b[100001], dp[100001];

deque<line*> cht;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1e18;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    dp[0] = 0;
    cht.push_front(new line(b[0], dp[0]));
    for(int i = 1; i < n; i++) {
        // Evaluate min
        while(cht.size() > 1) {
            int s = cht.size();
            if(cht[s-1]->eval(a[i]) > cht[s-2]->eval(a[i])) cht.pop_back();
            else break;
        }
        dp[i] = cht[cht.size() - 1]->eval(a[i]);
        // Insert new line
        line* newLine = new line(b[i], dp[i]);
        while(cht.size() > 1) {
            if(newLine->intersect(cht[0]) > newLine->intersect(cht[1])) cht.pop_front();
            else break;
        }
        cht.push_front(newLine);
    }
    cout << dp[n-1] << '\n';
}