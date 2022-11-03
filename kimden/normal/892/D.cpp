#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main() {
    ios_base::sync_with_stdio(false);
    // why this won't work?
    int n;
    cin >> n;
    vector<pll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    for(int i = 0; i < n; ++i){
        b[a[i].second] = a[(i + 1) % n].first;
    }
    for(int i = 0; i < n; ++i){
        if(i){
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;



}