#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using itn = int;



int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ptr1, ptr2;
    ptr1 = 0;
    ptr2 = m - 1;
    for(int i = 0; i < n; ++i){
        if(s[i] == '*'){
            break;
        }
        if(s[i] != t[ptr1]){
            cout << "NO" << endl;
            return 0;
        }
        ++ptr1;
    }
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '*'){
            break;
        }
        if(s[i] != t[ptr2]){
            cout << "NO" << endl;
            return 0;
        }
        --ptr2;
    }
    if(ptr1 == n){
        if(m == n) {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if(ptr2 - ptr1 >= -1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }



}