#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

ll a[N+5], b[N+5], en[N+5];
vector <ll> vec[N+5];
int l[N+5], r[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    set <int> s;
    for(int i=1; i<=n; i++){
        a[i] -= b[i];
        a[i] += a[i-1];
        vec[i].clear();
        if(a[i] != 0) s.insert(i);
    }
    queue <int> q;
    for(int i=1; i<=m; i++){
        cin >> l[i] >> r[i];
        l[i]--;
        if(a[l[i]] == 0 && a[r[i]] == 0){
            q.push(i);
        }
        else{
            en[i] = 2;
            if(a[l[i]]){
                vec[l[i]].push_back(i);
                en[i]--;
            }
            if(a[r[i]]){
                vec[r[i]].push_back(i);
                en[i]--;
            }
        }
    }
    while(!q.empty()){
        int id = q.front();
        q.pop();
        auto i = s.lower_bound(l[id]);
        while(i != s.end()){
            if(*i > r[id]) break;
            for(auto c : vec[*i]){
                en[c]++;
                if(en[c] == 2){
                    q.push(c);
                }
            }
            auto j = i;
            i++;
            s.erase(j);
        }
    }
    if(s.empty()) cout << "YES\n";
    else cout << "NO\n";
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