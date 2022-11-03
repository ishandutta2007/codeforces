#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    sort(all(b));
    if(sum <= b[n - 1] + b[n - 2]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



}