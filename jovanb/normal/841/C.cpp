#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int res[200005];
pair <int, int> b[200005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector <int> vec;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    for(int i=1; i<=n; i++){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b+1, b+1+n);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(int i=0; i<n; i++){
        res[b[i+1].second] = vec[i];
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
    return 0;
}