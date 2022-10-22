#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

ld f[N+5], g[N+5];
ld a[N+5];
ld pref[N+5];

int n;

ld dp[N+5];
int used[N+5];

struct line{
    ld k, n;
    ld eval(ld x){ return k*x + n; }
    ld intersect(line h){ return (n - h.n)/(h.k - k); }
};

void query(deque <pair <line, int>> &q, ld x){
    while(q.size() > 1 && q[0].first.eval(x) > q[1].first.eval(x)) q.pop_front();
}

void dodaj(deque <pair <line, int>> &q, pair <line, int> v){
    while(q.size() > 1){
        auto h = q.back();
        q.pop_back();
        if(q.back().first.intersect(h.first) <= h.first.intersect(v.first)){
            q.push_back(h);
            break;
        }
    }
    q.push_back(v);
}

void solve(ld pen){
    deque <pair <line, int>> q;
    q.push_front({{0, 0}, 0});
    for(int i=1; i<=n; i++){
        query(q, g[i]);
        dp[i] = pref[i] + q.front().first.eval(g[i]) - pen;
        used[i] = 1 + q.front().second;
        if(used[i] > 50){ used[n] = 500; break; }
        dodaj(q, {{-f[i], g[i]*f[i] - pref[i] + dp[i]}, used[i]});
    }
    while(!q.empty()) q.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        f[i] = f[i-1] + a[i];
        g[i] = g[i-1] + 1/a[i];
        pref[i] = pref[i-1] + f[i]/a[i];
    }
    ld l = -2e15, r = 0, d = -2e15;
    int turns = 120;
    while(turns--){
        ld mid = (l+r)/2;
        solve(mid);
        if(used[n] <= k) l = d = mid;
        else r = mid;
    }
    solve(d);
    cout << dp[n] + k*d << "\n";
    return 0;
}