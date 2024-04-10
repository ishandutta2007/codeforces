#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

set <pair <int, int>> q;

const int INF = 1000000005;

ll res;

void brisi(int l, int r){
    for(;;){
        auto c = q.lower_bound({l, 0});
        pair <int, int> pr = *c;
        if(pr.first > r) break;
        if(pr.second <= r){
            res -= pr.second - pr.first + 1;
            q.erase(pr);
            continue;
        }
        res -= (r+1) - pr.first;
        q.erase(pr);
        pr.first = r+1;
        q.insert(pr);
        break;
    }
    auto c = q.lower_bound({l, 0});
    c--;
    pair <int, int> pr = *c;
    if(pr.second < l) return;
    if(pr.second <= r){
        res -= pr.second - (l-1);
        q.erase(pr);
        pr.second = l-1;
        q.insert(pr);
        return;
    }
    res -= pr.second - pr.first + 1;
    q.erase(pr);
    pair <int, int> p1 = {pr.first, l-1};
    pair <int, int> p2 = {r+1, pr.second};
    res += (l-1) - pr.first + 1;
    res += pr.second - (r+1) + 1;
    q.insert(p1);
    q.insert(p2);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs;
    cin >> n >> qrs;
    q.insert({0, 0});
    q.insert({INF, INF});
    while(qrs--){
        int t, l, r;
        cin >> l >> r >> t;
        brisi(l, r);
        if(t == 1){
            res += r-l+1;
            q.insert({l, r});
        }
        cout << n - res << "\n";
    }
    return 0;
}

/*
4
2
1 2 1
3 4 1
*/