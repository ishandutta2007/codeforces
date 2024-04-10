#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

ll a[N+5];

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> a[i];
    if(m == 1){
        cout << 2 << "\n";
        return;
    }
    sort(a+1, a+1+m);
    priority_queue <ll> q;
    for(int i=2; i<=m; i++) q.push(a[i] - a[i - 1] - 1);
    q.push(a[1] + n - a[m] - 1);
    ll passed = 0;
    ll tot = 0;
    while(!q.empty()){
        int v = q.top();
        q.pop();
        v -= 2*passed;
        if(v <= 0) continue;
        if(v == 1){
            tot++;
            passed++;
        }
        else if(v == 2){
            tot++;
            passed++;
        }
        else{
            tot += v - 1;
            passed += 2;
        }
    }
    cout << n - tot << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
20 3
3 7 12
*/