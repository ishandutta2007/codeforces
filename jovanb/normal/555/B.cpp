#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct strukt{
    ll first, second, ind;
} niz[200005];

multiset <pair <ll, ll>> q;
pair <ll, ll> b[200005];
int res[200005];

ll l[200005];
ll r[200005];

bool cmp(strukt a, strukt b){
    if(a.first < b.first) return 1;
    if(a.first > b.first) return 0;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
    }
    for(int i=2; i<=n; i++){
        niz[i-1].first = l[i] - r[i-1];
        niz[i-1].second = r[i] - l[i-1];
        niz[i-1].ind = i-1;
    }
    n--;
    sort(niz+1, niz+1+n, cmp);
    for(int i=1; i<=m; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b+1, b+1+m);
    int tren = 0;
    for(int i=1; i<=m; i++){
        while(tren < n && niz[tren+1].first <= b[i].first){
            tren++;
            q.insert({niz[tren].second, niz[tren].ind});
        }
        if(!q.empty()){
            pair <ll, ll> par = *q.begin();
            if(par.first < b[i].first){
                cout << "No\n";
                return 0;
            }
            res[par.second] = b[i].second;
            q.erase(q.begin());
        }
    }
    if(tren != n || !q.empty()){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}