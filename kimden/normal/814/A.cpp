#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    a.resize(n);
    b.resize(k);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < k; ++i){
        cin >> b[i];
    }
    int ptr = 0;
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < n; ++i){
        if(a[i] == 0){
            a[i] = b[ptr];
            ++ptr;
        }
    }
    vector<int> c = a;
    sort(c.begin(), c.end());
    if(c == a){
        cout << "No" << endl;
    }else{

        cout << "Yes" << endl;
    }


    return 0;
}