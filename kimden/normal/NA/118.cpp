#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a, b;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(all(a));
    b = a;
    int ans = 0;
    int ptr = 1;
    for(int i = 0; i < n; ++i){
        while(ptr < n && a[ptr] <= a[i]){
            ++ptr;
        }
        if(ptr < n){
            ++ptr;
            ++ans;
        }
    }
    cout << ans << endl;


}