#include <bits/stdc++.h>
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

long long sqrt(long long n){
    if(n == 1) return 1;

    long long approx = ceil(sqrt((double)n));
    for(long long i = 0; i < 2; ++i)
        if((approx + i) * (approx + i) == n) return approx + i;

    return 0;
}

void solve(){
    lol n;
    cin >> n;

    lol ans = 0;
    for(lol i = 1; i * i <= n; ++i) ++ans;
    for(lol i = 1; i * i * i <= n; ++i) if(!sqrt(i)) ++ans;

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}