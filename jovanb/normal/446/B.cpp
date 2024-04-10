#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll row[1005];
ll col[1005];
ll niz1[1000005];
ll niz2[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m, k, p;
    cin >> n >> m >> k >> p;
    ll res=-1'000'000'000'000'000'000LL;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ll x;
            cin >> x;
            row[i] += x;
            col[j] += x;
        }
    }
    priority_queue <ll> pq;
    int l=1;
    for(int i=1; i<=n; i++){
        pq.push(row[i]);
    }
    while(l <= k){
        ll x = pq.top();
        niz1[l] = x+niz1[l-1];
        pq.pop();
        l++;
        pq.push(x-m*p);
    }
    l = 1;
    while(!pq.empty()) pq.pop();
    for(int i=1; i<=m; i++){
        pq.push(col[i]);
    }
    while(l <= k){
        ll x = pq.top();
        niz2[l] = x+niz2[l-1];
        pq.pop();
        l++;
        pq.push(x-n*p);
    }
    for(int i=0; i<=k; i++){
        int j = k-i;
        res = max(res, niz1[i]+niz2[j]-1LL*i*j*p);
    }
    cout << res;
    return 0;
}