#define x firsts
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

int minpos[1001], maxpos[1001];

void init(){
    for(int i = 1; i < 1001; ++i){
        minpos[i] = inf;
        maxpos[i] = -inf;
    }
}

void solve(){
    int n;
    cin >> n;

    init();

    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        minpos[arr[i]] = min(minpos[arr[i]], i + 1);
        maxpos[arr[i]] = max(maxpos[arr[i]], i + 1);
    }

    int ans = -1;

    for(int i = 1; i < 1001; ++i)
        for(int j = i; j < 1001; ++j) if(__gcd(i, j) == 1){
            ans = max(ans, maxpos[i] + maxpos[j]);
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