#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n, 0);
    if(k == 1){
        cout << 1;
    }else{
        cout << 0;
    }
    for(int i = 1; i < n; ++i){
        int cur = p[i - 1];
        while(cur >= 0){
            if(s[i] == s[cur]){
                p[i] = cur + 1;
                break;
            }
            if(cur == 0){
                break;
            }
            cur = p[cur - 1];
        }
        int m = (i + 1) / (i + 1 - p[i]);
        int q = (i + 1) % (i + 1 - p[i]);
        int l = i + 1;
        bool b;
        if(q == 0){
            b = (m / k) - (m % k) >= 0;
        }else{
            b = (m / k) - (m % k) > 0;
        }
        if(b){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;


}