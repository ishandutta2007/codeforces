#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<int> p(n, 0);
    int x;
    for(int i = 0; i < n; ++i){
        cout << 1 << endl;
        cin >> x;
        if(x == 0){
            return 0;
        }
        if(x == 1){
            p[i] = 1;
        }else{
            p[i] = 0;
        }
    }
    int L = 1, R = m + 1;
    int mid;
    int ptr = 0;
    while(R - L > 1){
        mid = (R + L) / 2;
        cout << mid << endl;
        cin >> x;
        if(x == 0){
            return 0;
        }
        if(p[ptr] == 0){
            x = -x;
        }
        if(x > 0){
            L = mid;
        }else{
            R = mid;
        }
        ++ptr;
        ptr %= n;
    }



    return 0;
}