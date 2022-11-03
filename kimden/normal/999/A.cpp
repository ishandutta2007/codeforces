#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] <= k){
            ++x;
            ++y;
            continue;
        }else{
            break;
        }
    }
    if(x < n){
        for(int i = n - 1; i >= 0; --i){
            if(a[i] <= k){
                ++y;
            }else{
                break;
            }
        }
    }
    cout << y << endl;



}