#define x first
#define y second

#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int maxn = 2e5 + 88;
int arr[maxn], f[maxn];

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        f[i] = f[i - 1];
        if(arr[i] < i) ++f[i];
    }

    lol ans = 0;
    for(int i = 1; i <= n; ++i) if(arr[i] < i){
        ans += f[arr[i] - 1];
    }

    cout << ans << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}