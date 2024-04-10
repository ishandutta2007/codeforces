#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll best[100005];
ll val[100005];
ll col[100005];

const ll INF = 10000000000000LL;

pair <ll, int> mx1;
pair <ll, int> mx2;

void upd(pair <ll, int> novi){
    if(novi.second == mx1.second){
        mx1.first = max(mx1.first, novi.first);
        return;
    }
    if(novi.second == mx2.second){
        mx2.first = max(mx2.first, novi.first);
        if(mx1.first < mx2.first) swap(mx1, mx2);
        return;
    }
    if(mx2.first < novi.first) mx2 = novi;
    if(mx1.first < mx2.first) swap(mx1, mx2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> val[i];
    }
    for(int i=1; i<=n; i++){
        cin >> col[i];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        for(int i=1; i<=n; i++) best[i] = -INF;
        ll res = 0;
        mx1 = {-INF, 0};
        mx2 = {-INF, 0};
        for(int i=1; i<=n; i++){
            ll now = b*val[i];
            if(mx1.second == col[i]){
                now = max(now, a*val[i]+mx1.first);
            }
            else now = max(now, b*val[i]+mx1.first);
            if(mx2.second == col[i]){
                now = max(now, a*val[i]+mx2.first);
            }
            else now = max(now, b*val[i]+mx2.first);
            now = max(now, best[col[i]] + a*val[i]);
            res = max(res, now);
            best[col[i]] = max(best[col[i]], now);
            upd({best[col[i]], col[i]});
        }
        cout << res << "\n";
    }
    return 0;
}