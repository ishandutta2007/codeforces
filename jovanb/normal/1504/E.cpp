#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 100000;

const ll INF = 10000000000000000LL;

ll dist[MAXN+5];
pair <int, int> a[MAXN+5];
vector <pair <int, int>> graf[MAXN+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    ll res = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i].first >> a[i].second;
        res += a[i].second;
    }
    sort(a+1, a+1+n);
    for(int i=1; i<n; i++){
        auto j = upper_bound(a+1, a+1+n, make_pair(a[i].first+a[i].second, 1000000000));
        j--;
        int id = j - a;
        graf[i].push_back({id, 0});
        graf[i].push_back({id+1, a[id+1].first - a[i].first - a[i].second});
    }
    for(int i=2; i<=n; i++){
        graf[i].push_back({i-1, 0});
        dist[i] = INF;
    }
    set <pair <ll, int>> q;
    q.insert({0, 1});
    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for(auto pr : graf[v]){
            int c = pr.first;
            int d = pr.second;
            if(dist[c] > dist[v] + d){
                q.erase({dist[c], c});
                dist[c] = dist[v] + d;
                q.insert({dist[c], c});
            }
        }
    }
    cout << res + dist[n] << "\n";
    return 0;
}