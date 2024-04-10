#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int x, a, y, b;

ll k;

int niz[200005];

bool check(int n){
    priority_queue <ll> q1;
    priority_queue <ll> q2;
    for(int i=1; i<=n; i++){
        if(i%a == 0 && i%b == 0){
            q2.push(x+y);
        }
        else if(i%a == 0){
            q2.push(x);
        }
        else if(i%b == 0){
            q2.push(y);
        }
    }
    ll sum = 0;
    int cnt = 0;
    while(!q2.empty()){
        sum += niz[++cnt]*q2.top();
        q2.pop();
    }
    return sum >= k;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        niz[i] /= 100;
    }
    sort(niz+1, niz+1+n);
    reverse(niz+1, niz+1+n);
    cin >> x >> a;
    cin >> y >> b;
    cin >> k;
    int l = 1, r = n, res = n+1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    if(res == n+1){
        cout << "-1\n";
    }
    else cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}