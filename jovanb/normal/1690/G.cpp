#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

int a[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    set <pair <int, int>> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(q.empty() || q.rbegin()->second > a[i]) q.insert({i, a[i]});
    }
    while(m--){
        int i, d;
        cin >> i >> d;
        auto c = q.lower_bound({i, a[i]});
        while(c != q.end() && c->second >= a[i] - d){
            auto h = c;
            c++;
            q.erase(h);
        }
        a[i] -= d;
        c = q.lower_bound({i, 0});
        if(c == q.begin()){
            q.insert({i, a[i]});
        }
        else{
            c--;
            if(c->second > a[i]){
                q.insert({i, a[i]});
            }
        }
        cout << q.size() << " ";
    }
    cout << "\n";
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