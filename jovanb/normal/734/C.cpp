#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

pair <ull, ull> a[200005];
pair <ull, ull> b[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, m, k;
    cin >> n >> m >> k;
    ull x, s;
    cin >> x >> s;
    ull mn;
    mn = x*n;
    for(int i=1; i<=m; i++){
        cin >> a[i].second;
    }
    for(int i=1; i<=m; i++){
        cin >> a[i].first;
    }
    for(int i=1; i<=k; i++){
        cin >> b[i].second;
    }
    for(int i=1; i<=k; i++){
        cin >> b[i].first;
    }
    sort(b+1, b+1+k);
    for(int i=2; i<=k; i++){
        b[i].second = max(b[i].second, b[i-1].second);
    }
    for(int i=1; i<=m; i++){
        if(a[i].first <= s){
            ull g = s-a[i].first;
            ull l = 1, r = k, res = 0;
            while(l <= r){
                ull mid = (l+r)/2;
                if(b[mid].first <= g){
                    res = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            ull ost = max(0ULL, n-b[res].second);
            //cout << ost << " " << a[i].second << endl;
            mn = min(mn, ost*a[i].second);
        }
    }
    ull l = 1, r = k, res = 0;
    while(l <= r){
        ull mid = (l+r)/2;
        if(b[mid].first <= s){
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    ull ost = max(0ULL, n-b[res].second);
    mn = min(mn, ost*x);
    cout << mn;
    return 0;
}