/*
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

typedef long long ll;
typedef long double ld;

pair <ll, ll> par[1005];
bool ima[1005];
ll pre[1005];
pair <ll, ll> niz1[1005];

int n, m;
int br[1005];

ll res(){
    ll ukup=0;
    for(int i=1; i<=n; i++) pre[i] = pre[i-1]+ima[i];
    for(int i=1; i<=m; i++){
        ll l = par[i].first;
        ll r = par[i].second;
        ll x = pre[r]-pre[l-1];
        ukup += x*(r-l+1-x);
    }
    return ukup;
}

bool cmp(pair <ll, ll> a, pair <ll, ll> b){
    return a.second-a.first > b.second-b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> par[i].first >> par[i].second;
    }
    sort(par+1, par+1+m, cmp);
    for(int j=1; j<=m; j++){
        int l = par[j].first;
        int r = par[j].second;
        for(int i=l; i<=r; i++){
            ll res1 = res();
            ima[i] = 1;
            ll res2 = res();
            ima[i] = 0;
            if(res1 < res2) ima[i] = 1;
        }
    }
    for(int i=1; i<=n; i++) cout << ima[i];
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool broj[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cout << i%2;
    }
    return 0;
}